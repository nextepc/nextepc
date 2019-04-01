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


#ifndef __PGW_GX_HANDLER_H__
#define __PGW_GX_HANDLER_H__

#include "gtp/gtp_message.h"

#include "pgw_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) pgw_gx_handle_cca_initial_request(
        pgw_sess_t *sess, gx_message_t *gx_message,
        gtp_xact_t *xact, gtp_create_session_request_t *req);
CORE_DECLARE(void) pgw_gx_handle_cca_termination_request(
        pgw_sess_t *sess, gx_message_t *gx_message,
        gtp_xact_t *xact, gtp_delete_session_request_t *req);
CORE_DECLARE(void) pgw_gx_handle_re_auth_request(
        pgw_sess_t *sess, gx_message_t *gx_message);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PGW_GX_HANDLER_H__ */
