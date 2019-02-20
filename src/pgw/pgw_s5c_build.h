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


#ifndef __PGW_S5C_BUILD_H__
#define __PGW_S5C_BUILD_H__

#include "gtp/gtp_message.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) pgw_s5c_build_create_session_response(
        pkbuf_t **pkbuf, c_uint8_t type, pgw_sess_t *sess,
        gx_message_t *gx_message, gtp_create_session_request_t *req);
CORE_DECLARE(status_t) pgw_s5c_build_delete_session_response(
        pkbuf_t **pkbuf, c_uint8_t type,
        gx_message_t *gx_message, gtp_delete_session_request_t *req);

CORE_DECLARE(status_t) pgw_s5c_build_create_bearer_request(
        pkbuf_t **pkbuf, c_uint8_t type, pgw_bearer_t *bearer);
CORE_DECLARE(status_t) pgw_s5c_build_update_bearer_request(
        pkbuf_t **pkbuf, c_uint8_t type, pgw_bearer_t *bearer,
        int qos_presence, int tft_presence);
CORE_DECLARE(status_t) pgw_s5c_build_delete_bearer_request(
        pkbuf_t **pkbuf, c_uint8_t type, pgw_bearer_t *bearer);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PGW_S5C_BUILD_H__ */
