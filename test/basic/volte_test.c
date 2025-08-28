/*************************************************************************** 

    Copyright (C) 2019 NextEPC Inc. All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***************************************************************************/



#include "core_debug.h"
#include "core_pkbuf.h"
#include "core_lib.h"
#ifdef HAVE_MONGOC2
#include <mongoc/mongoc.h>
#else
#include <mongoc.h>
#endif

#include "common/context.h"
#include "mme/mme_context.h"
#include "s1ap/s1ap_message.h"

#include "testutil.h"
#include "testpacket.h"

static void volte_test1(abts_case *tc, void *data)
{
    status_t rv;
    sock_id sock;
    pkbuf_t *sendbuf;
    pkbuf_t *recvbuf;
    s1ap_message_t message;
    int i;
    int msgindex = 0;

    mongoc_collection_t *collection = NULL;
    bson_t *doc = NULL;
    c_int64_t count = 0;
    bson_error_t error;
    const char *json =
    "{"
      "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2b\" }," 
      "\"imsi\" : \"001010123456819\","
      "\"pdn\" : ["
      "{ \"apn\" : \"internet\","
        "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd32\" },"
        "\"qos\" : {"
          "\"qci\" : 9,"
          "\"arp\" : {"
            "\"priority_level\" : 8,"
            "\"pre_emption_vulnerability\" : 1,"
            "\"pre_emption_capability\" : 1 } },"
        "\"type\" : 2 },"
      "{ \"apn\" : \"internet.ng2.mnet\","
        "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2c\" },"
        "\"pcc_rule\" : ["
        "{ \"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2d\" },"
          "\"qos\" : {"
            "\"qci\" : 1,"
            "\"gbr\" : {"
              "\"downlink\" : { \"$numberLong\" : \"64\" },"
              "\"uplink\" : { \"$numberLong\" : \"44\" } },"
            "\"mbr\" : {"
              "\"downlink\" : { \"$numberLong\" : \"64\" },"
              "\"uplink\" : { \"$numberLong\" : \"44\" } },"
            "\"arp\" : {"
              "\"priority_level\" : 3,"
              "\"pre_emption_vulnerability\" : 0,"
              "\"pre_emption_capability\" : 0 } },"
          "\"flow\" : ["
          "{ \"direction\" : 2,"
            "\"description\" : \"permit out udp from any 1-65535 to 10.200.136.98/32 23454\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd31\" } },"
          "{ \"direction\" : 1,"
            "\"description\" : \"permit out udp from any 50020 to 10.200.136.98/32 1-65535\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd30\" } },"
          "{ \"direction\" : 2,"
            "\"description\" : \"permit out udp from any 1-65535 to 10.200.136.98/32 23455\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2f\" } },"
          "{ \"direction\" : 1,"
            "\"description\" : \"permit out udp from any 50021 to 10.200.136.98/32 1-65535\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2e\" } } ]"
        "} ],"
        "\"ambr\" : {"
          "\"downlink\" : { \"$numberLong\" : \"35840\" },"
          "\"uplink\" : { \"$numberLong\" : \"15360\" } },"
        "\"qos\" : {"
          "\"qci\" : 6,"
          "\"arp\" : {"
            "\"priority_level\" : 6,"
            "\"pre_emption_vulnerability\" : 1,"
            "\"pre_emption_capability\" : 1 } },"
        "\"type\" : 2 }"
      "],"
      "\"ambr\" : {"
        "\"downlink\" : { \"$numberLong\" : \"1024000\" },"
        "\"uplink\" : { \"$numberLong\" : \"1024000\" } },"
      "\"subscribed_rau_tau_timer\" : 12,"
      "\"network_access_mode\" : 2,"
      "\"subscriber_status\" : 0,"
      "\"access_restriction_data\" : 32,"
      "\"security\" : {"
          "\"k\" : \"465B5CE8 B199B49F AA5F0A2E E238A6BC\","
          "\"op\" : \"5F1D289C 5D354D0A 140C2548 F5F3E3BA\","
          "\"amf\" : \"8000\","
          "\"sqn\" : { \"$numberLong\" : \"64\" }, "
          "\"rand\" : \"20080C38 18183B52 2614162C 07601D0D\" }, "
      "\"__v\" : 0"
    "}";

    /* eNB connects to MME */
    rv = tests1ap_enb_connect(&sock);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Send S1-Setup Reqeust */
    rv = tests1ap_build_setup_req(
            &sendbuf, S1AP_ENB_ID_PR_macroENB_ID, 0x54f64);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive S1-Setup Response */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = s1ap_decode_pdu(&message, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    s1ap_free_pdu(&message);
    pkbuf_free(recvbuf);

    collection = mongoc_client_get_collection(
        context_self()->db_client,
        context_self()->db_name, "subscribers");
    ABTS_PTR_NOTNULL(tc, collection);

    doc = bson_new_from_json((const uint8_t *)json, -1, &error);;
    ABTS_PTR_NOTNULL(tc, doc);
    ABTS_TRUE(tc, mongoc_collection_insert(collection, 
                MONGOC_INSERT_NONE, doc, NULL, &error));
    bson_destroy(doc);

    doc = BCON_NEW("imsi", BCON_UTF8("001010123456819"));
    ABTS_PTR_NOTNULL(tc, doc);
    do
    {
#if MONGOC_MAJOR_VERSION >= 2
        count = mongoc_collection_count_documents (
            collection, doc, NULL, NULL, NULL, &error);
#else
        count = mongoc_collection_count (
            collection, MONGOC_QUERY_NONE, doc, 0, 0, NULL, &error);
#endif
    } while (count == 0);
    bson_destroy(doc);

    /***********************************************************************
     * Attach Request : Known IMSI, Integrity Protected, No Security Context
     * Send Initial-UE Message + Attach Request + PDN Connectivity        */
    rv = tests1ap_build_initial_ue_msg(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Authentication Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send Authentication Response */
    rv = tests1ap_build_authentication_response(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Security mode Command */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send Security mode Complete */
    rv = tests1ap_build_security_mode_complete(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive ESM Information Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send ESM Information Response */
    rv = tests1ap_build_esm_information_response(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Initial Context Setup Request + 
     * Attach Accept + 
     * Activate Default Bearer Context Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send UE Capability Info Indication */
    rv = tests1ap_build_ue_capability_info_indication(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Initial Context Setup Response */
    rv = tests1ap_build_initial_context_setup_response(&sendbuf, 1, 1, 5, 1);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Attach Complete + Activate default EPS bearer cotext accept */
    rv = tests1ap_build_attach_complete(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive EMM information */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send PDN Connectivity Request */
    rv = tests1ap_build_pdn_connectivity_request(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive E-RAB Setup Request +
     * Activate default EPS bearer context request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send E-RAB Setup Response */
    rv = tests1ap_build_e_rab_setup_response(&sendbuf, 1, 1, 6, 2);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Activate default EPS bearer context accept */
    rv = tests1ap_build_activate_default_bearer_accept(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive E-RAB Setup Request +
     * Activate dedicated EPS bearer context request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send Activate dedicated EPS bearer context accept */
    rv = tests1ap_build_activate_dedicated_bearer_accept(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send E-RAB Setup Response */
    rv = tests1ap_build_e_rab_setup_response(&sendbuf, 1, 1, 7, 3);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send PDN disconnectivity request */
    rv = tests1ap_build_pdn_disconnectivity_request(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive E-RAB Release Command +
     * Deactivate EPS bearer context request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send E-RAB Release Response */
    rv = tests1ap_build_e_rab_release_response(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(1000));

    /* Deactivate EPS bearer context accept */
    rv = tests1ap_build_deactivate_bearer_accept(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send INVALID PDN Connectivity Request */
    rv = tests1ap_build_pdn_connectivity_request(&sendbuf, msgindex+1);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive PDN Connectivity Reject */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /********** Remove Subscriber in Database */
    doc = BCON_NEW("imsi", BCON_UTF8("001010123456819"));
    ABTS_PTR_NOTNULL(tc, doc);
    ABTS_TRUE(tc, mongoc_collection_remove(collection, 
            MONGOC_REMOVE_SINGLE_REMOVE, doc, NULL, &error)) 
    bson_destroy(doc);

    mongoc_collection_destroy(collection);

    /* eNB disonncect from MME */
    rv = tests1ap_enb_close(sock);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));
}

static void volte_test2(abts_case *tc, void *data)
{
    status_t rv;
    sock_id sock;
    pkbuf_t *sendbuf;
    pkbuf_t *recvbuf;
    s1ap_message_t message;
    int i;
    int msgindex = 0;

    mongoc_collection_t *collection = NULL;
    bson_t *doc = NULL;
    c_int64_t count = 0;
    bson_error_t error;
    const char *json =
    "{"
      "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2b\" }," 
      "\"imsi\" : \"001010123456819\","
      "\"pdn\" : ["
      "{ \"apn\" : \"internet.ng2.mnet\","
        "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd32\" },"
        "\"qos\" : {"
          "\"qci\" : 9,"
          "\"arp\" : {"
            "\"priority_level\" : 8,"
            "\"pre_emption_vulnerability\" : 1,"
            "\"pre_emption_capability\" : 1 } },"
        "\"type\" : 2 },"
      "{ \"apn\" : \"internet\","
        "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2c\" },"
        "\"pcc_rule\" : ["
        "{ \"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2d\" },"
          "\"qos\" : {"
            "\"qci\" : 1,"
            "\"gbr\" : {"
              "\"downlink\" : { \"$numberLong\" : \"64\" },"
              "\"uplink\" : { \"$numberLong\" : \"44\" } },"
            "\"mbr\" : {"
              "\"downlink\" : { \"$numberLong\" : \"64\" },"
              "\"uplink\" : { \"$numberLong\" : \"44\" } },"
            "\"arp\" : {"
              "\"priority_level\" : 3,"
              "\"pre_emption_vulnerability\" : 0,"
              "\"pre_emption_capability\" : 0 } },"
          "\"flow\" : ["
          "{ \"direction\" : 2,"
            "\"description\" : \"permit out udp from any 1-65535 to 10.200.136.98/32 23454\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd31\" } },"
          "{ \"direction\" : 1,"
            "\"description\" : \"permit out ip from 45.45.0.1 to any\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd30\" } },"
          "{ \"direction\" : 2,"
            "\"description\" : \"permit out udp from any 1-65535 to 10.200.136.98/24 23455\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2f\" } },"
          "{ \"direction\" : 1,"
            "\"description\" : \"permit out ip from cafe::1 to any\","
            "\"_id\" : { \"$oid\" : \"599eb929c850caabcbfdcd2e\" } } ]"
        "} ],"
        "\"ambr\" : {"
          "\"downlink\" : { \"$numberLong\" : \"35840\" },"
          "\"uplink\" : { \"$numberLong\" : \"15360\" } },"
        "\"qos\" : {"
          "\"qci\" : 6,"
          "\"arp\" : {"
            "\"priority_level\" : 6,"
            "\"pre_emption_vulnerability\" : 1,"
            "\"pre_emption_capability\" : 1 } },"
        "\"type\" : 2 }"
      "],"
      "\"ambr\" : {"
        "\"downlink\" : { \"$numberLong\" : \"1024000\" },"
        "\"uplink\" : { \"$numberLong\" : \"1024000\" } },"
      "\"subscribed_rau_tau_timer\" : 12,"
      "\"network_access_mode\" : 2,"
      "\"subscriber_status\" : 0,"
      "\"access_restriction_data\" : 32,"
      "\"security\" : {"
          "\"k\" : \"465B5CE8 B199B49F AA5F0A2E E238A6BC\","
          "\"op\" : \"5F1D289C 5D354D0A 140C2548 F5F3E3BA\","
          "\"amf\" : \"8000\","
          "\"sqn\" : { \"$numberLong\" : \"64\" }, "
          "\"rand\" : \"20080C38 18183B52 2614162C 07601D0D\" }, "
      "\"__v\" : 0"
    "}";

    /* eNB connects to MME */
    rv = tests1ap_enb_connect(&sock);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Send S1-Setup Reqeust */
    rv = tests1ap_build_setup_req(
            &sendbuf, S1AP_ENB_ID_PR_macroENB_ID, 0x54f64);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive S1-Setup Response */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = s1ap_decode_pdu(&message, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    s1ap_free_pdu(&message);
    pkbuf_free(recvbuf);

    collection = mongoc_client_get_collection(
        context_self()->db_client,
        context_self()->db_name, "subscribers");
    ABTS_PTR_NOTNULL(tc, collection);

    doc = bson_new_from_json((const uint8_t *)json, -1, &error);;
    ABTS_PTR_NOTNULL(tc, doc);
    ABTS_TRUE(tc, mongoc_collection_insert(collection, 
                MONGOC_INSERT_NONE, doc, NULL, &error));
    bson_destroy(doc);

    doc = BCON_NEW("imsi", BCON_UTF8("001010123456819"));
    ABTS_PTR_NOTNULL(tc, doc);
    do
    {
#if MONGOC_MAJOR_VERSION >= 2
        count = mongoc_collection_count_documents (
            collection, doc, NULL, NULL, NULL, &error);
#else
        count = mongoc_collection_count (
            collection, MONGOC_QUERY_NONE, doc, 0, 0, NULL, &error);
#endif
    } while (count == 0);
    bson_destroy(doc);

    /***********************************************************************
     * Attach Request : Known IMSI, Integrity Protected, MAC failed
     * Send Initial-UE Message + Attach Request + PDN Connectivity        */
    rv = tests1ap_build_initial_ue_msg(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Authentication Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send Authentication Response */
    rv = tests1ap_build_authentication_response(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Security mode Command */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send Security mode Complete */
    rv = tests1ap_build_security_mode_complete(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive ESM Information Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send ESM Information Response */
    rv = tests1ap_build_esm_information_response(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive Initial Context Setup Request + 
     * Attach Accept + 
     * Activate Default Bearer Context Request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send UE Capability Info Indication */
    rv = tests1ap_build_ue_capability_info_indication(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Initial Context Setup Response */
    rv = tests1ap_build_initial_context_setup_response(&sendbuf,
            16777373, 1, 5, 1);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Attach Complete + Activate default EPS bearer cotext accept */
    rv = tests1ap_build_attach_complete(&sendbuf, msgindex);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    /* Receive EMM information */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Receive E-RAB Setup Request + 
     * Activate dedicated EPS bearer context request */
    recvbuf = pkbuf_alloc(0, MAX_SDU_LEN);
    rv = tests1ap_enb_read(sock, recvbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    pkbuf_free(recvbuf);

    /* Send E-RAB Setup Response */
    rv = tests1ap_build_e_rab_setup_response(&sendbuf, 33554492, 1, 6, 2);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));

    /* Send Activate dedicated EPS bearer context accept */
    rv = tests1ap_build_activate_dedicated_bearer_accept(&sendbuf, msgindex+1);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);
    rv = tests1ap_enb_send(sock, sendbuf);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

#if 0 /* TFT Rule Tester */
    core_sleep(time_from_msec(300));

    /* Send GTP-U ICMP Packet */
#if 1
    rv = testgtpu_build_ping(&sendbuf, "45.45.0.2", "45.45.0.1");
#else
    rv = testgtpu_build_ping(&sendbuf, "cafe::2", "cafe::1");
#endif
    rv = testgtpu_enb_send(sendbuf);

    core_sleep(time_from_msec(300));
#endif

    /********** Remove Subscriber in Database */
    doc = BCON_NEW("imsi", BCON_UTF8("001010123456819"));
    ABTS_PTR_NOTNULL(tc, doc);
    ABTS_TRUE(tc, mongoc_collection_remove(collection, 
            MONGOC_REMOVE_SINGLE_REMOVE, doc, NULL, &error)) 
    bson_destroy(doc);

    mongoc_collection_destroy(collection);

    /* eNB disonncect from MME */
    rv = tests1ap_enb_close(sock);
    ABTS_INT_EQUAL(tc, CORE_OK, rv);

    core_sleep(time_from_msec(300));
}

abts_suite *test_volte(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, volte_test1, NULL);
    abts_run_test(suite, volte_test2, NULL);

    return suite;
}
