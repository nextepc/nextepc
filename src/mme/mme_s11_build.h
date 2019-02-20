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


#ifndef __MME_S11_BUILD_H__
#define __MME_S11_BUILD_H__

#include "gtp/gtp_message.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) mme_s11_build_create_session_request(
        pkbuf_t **pkbuf, c_uint8_t type, mme_sess_t *sess);
CORE_DECLARE(status_t) mme_s11_build_modify_bearer_request(pkbuf_t **pkbuf,
        c_uint8_t type, mme_bearer_t *bearer, int uli_presense);
CORE_DECLARE(status_t) mme_s11_build_delete_session_request(
        pkbuf_t **pkbuf, c_uint8_t type, mme_sess_t *sess);
CORE_DECLARE(status_t) mme_s11_build_create_bearer_response(
        pkbuf_t **pkbuf, c_uint8_t type, mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_s11_build_update_bearer_response(
        pkbuf_t **pkbuf, c_uint8_t type, mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_s11_build_delete_bearer_response(
        pkbuf_t **pkbuf, c_uint8_t type, mme_bearer_t *bearer);
CORE_DECLARE(status_t) mme_s11_build_release_access_bearers_request(
        pkbuf_t **pkbuf, c_uint8_t type);
CORE_DECLARE(status_t) mme_s11_build_downlink_data_notification_ack(
        pkbuf_t **pkbuf, c_uint8_t type);
CORE_DECLARE(status_t)
        mme_s11_build_create_indirect_data_forwarding_tunnel_request(
            pkbuf_t **pkbuf, c_uint8_t type, mme_ue_t *mme_ue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_S11_BUILD_H__ */
