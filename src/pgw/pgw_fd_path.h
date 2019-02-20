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


#ifndef __PGW_FD_PATH_H__
#define __PGW_FD_PATH_H__

#include "core_errno.h"

#include "pgw_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _gtp_xact_t gtp_xact_t;

CORE_DECLARE(status_t) pgw_fd_init(void);
CORE_DECLARE(void) pgw_fd_final(void);

CORE_DECLARE(void) pgw_gx_send_ccr(pgw_sess_t *sess, gtp_xact_t *xact,
        pkbuf_t *gtpbuf, c_uint32_t cc_request_type);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PGW_FD_PATH_H__ */

