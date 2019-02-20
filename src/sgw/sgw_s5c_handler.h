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


#ifndef __SGW_S5C_HANDLER_H__
#define __SGW_S5C_HANDLER_H__

#include "gtp/gtp_message.h"

#include "sgw_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) sgw_s5c_handle_create_session_response(gtp_xact_t *s5c_xact,
        sgw_sess_t *sess, gtp_message_t *gtp_message);
CORE_DECLARE(void) sgw_s5c_handle_delete_session_response(gtp_xact_t *s5c_xact,
        sgw_sess_t *sess, gtp_message_t *gtp_message);
CORE_DECLARE(void) sgw_s5c_handle_create_bearer_request(gtp_xact_t *s5c_xact,
        sgw_sess_t *sess, gtp_message_t *gtp_message);
CORE_DECLARE(void) sgw_s5c_handle_update_bearer_request(gtp_xact_t *s5c_xact, 
    sgw_sess_t *sess, gtp_message_t *gtp_message);
CORE_DECLARE(void) sgw_s5c_handle_delete_bearer_request(gtp_xact_t *s5c_xact, 
    sgw_sess_t *sess, gtp_message_t *gtp_message);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SGW_S5C_HANDLER_H__ */
