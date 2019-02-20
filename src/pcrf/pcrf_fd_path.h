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


#ifndef __PCRF_FD_PATH_H__
#define __PCRF_FD_PATH_H__

#include "core_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct sess_state;
typedef struct _rx_message_t rx_message_t;

CORE_DECLARE(status_t) pcrf_fd_init(void);
CORE_DECLARE(void) pcrf_fd_final(void);

CORE_DECLARE(status_t) pcrf_gx_init(void);
CORE_DECLARE(void) pcrf_gx_final(void);
CORE_DECLARE(status_t) pcrf_rx_init(void);
CORE_DECLARE(void) pcrf_rx_final(void);

CORE_DECLARE(status_t) pcrf_gx_send_rar(
        c_uint8_t *gx_sid, c_uint8_t *rx_sid, rx_message_t *rx_message);
CORE_DECLARE(status_t) pcrf_rx_send_asr(
        c_uint8_t *rx_sid, c_uint32_t abort_cause);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PCRF_FD_PATH_H__ */

