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


#ifndef __MME_S11_HANDLER_H__
#define __MME_S11_HANDLER_H__

#include "gtp/gtp_message.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) mme_s11_handle_create_session_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_create_session_response_t *rsp);
CORE_DECLARE(void) mme_s11_handle_modify_bearer_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_modify_bearer_response_t *rsp);
CORE_DECLARE(void) mme_s11_handle_delete_session_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_delete_session_response_t *rsp);
CORE_DECLARE(void) mme_s11_handle_create_bearer_request(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_create_bearer_request_t *rsp);
CORE_DECLARE(void) mme_s11_handle_update_bearer_request(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_update_bearer_request_t *rsp);
CORE_DECLARE(void) mme_s11_handle_delete_bearer_request(
        gtp_xact_t *xact, mme_ue_t *mme_ue, gtp_delete_bearer_request_t *rsp);

CORE_DECLARE(void) mme_s11_handle_release_access_bearers_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue,
        gtp_release_access_bearers_response_t *rsp);
CORE_DECLARE(void) mme_s11_handle_downlink_data_notification(
        gtp_xact_t *xact, mme_ue_t *mme_ue,
        gtp_downlink_data_notification_t *noti);
CORE_DECLARE(void) mme_s11_handle_create_indirect_data_forwarding_tunnel_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue,
        gtp_create_indirect_data_forwarding_tunnel_response_t *rsp);
CORE_DECLARE(void) mme_s11_handle_delete_indirect_data_forwarding_tunnel_response(
        gtp_xact_t *xact, mme_ue_t *mme_ue,
        gtp_delete_indirect_data_forwarding_tunnel_response_t *rsp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_S11_HANDLER_H__ */
