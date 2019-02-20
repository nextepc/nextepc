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


#ifndef __MME_S11_PATH_H__
#define __MME_S11_PATH_H__

#include "core_pkbuf.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) mme_gtp_open();
CORE_DECLARE(status_t) mme_gtp_close();

CORE_DECLARE(status_t) mme_gtp_send_create_session_request(mme_sess_t *sess);
CORE_DECLARE(status_t) mme_gtp_send_modify_bearer_request(
        mme_bearer_t *bearer, int uli_presence);
CORE_DECLARE(status_t) mme_gtp_send_delete_session_request(mme_sess_t *sess);
CORE_DECLARE(status_t) mme_gtp_send_delete_all_sessions(mme_ue_t *mme_ue);
CORE_DECLARE(status_t) mme_gtp_send_create_bearer_response(mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_gtp_send_update_bearer_response(mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_gtp_send_delete_bearer_response(mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_gtp_send_release_access_bearers_request(mme_ue_t *mme_ue);

CORE_DECLARE(status_t) mme_gtp_send_create_indirect_data_forwarding_tunnel_request(
        mme_ue_t *mme_ue);
CORE_DECLARE(status_t) mme_gtp_send_delete_indirect_data_forwarding_tunnel_request(
        mme_ue_t *mme_ue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_S11_PATH_H__ */
