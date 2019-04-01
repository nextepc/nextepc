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


#ifndef __S1AP_HANDLER_H__
#define __S1AP_HANDLER_H__

#include "s1ap/s1ap_message.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) s1ap_handle_s1_setup_request(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_initial_ue_message(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_uplink_nas_transport(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_ue_capability_info_indication(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_initial_context_setup_response(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_initial_context_setup_failure(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_e_rab_setup_response(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_ue_context_release_request(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_ue_context_release_complete(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_paging(mme_ue_t *mme_ue);

CORE_DECLARE(void) s1ap_handle_path_switch_request(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_handover_required(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_handover_request_ack(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_handover_failure(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_handover_cancel(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_enb_status_transfer(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_enb_configuration_transfer(
        mme_enb_t *enb, s1ap_message_t *message, pkbuf_t *pkbuf);
CORE_DECLARE(void) s1ap_handle_handover_notification(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_s1_reset(
        mme_enb_t *enb, s1ap_message_t *message);

CORE_DECLARE(void) s1ap_handle_write_replace_warning_response(
        mme_enb_t *enb, s1ap_message_t *message);
CORE_DECLARE(void) s1ap_handle_kill_response(
        mme_enb_t *enb, s1ap_message_t *message);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __S1AP_HANDLER_H__ */
