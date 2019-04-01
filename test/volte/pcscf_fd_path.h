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


#ifndef __PCSCF_FD_PATH_H__
#define __PCSCF_FD_PATH_H__

#include "core_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) pcscf_fd_init(void);
CORE_DECLARE(void) pcscf_fd_final(void);

CORE_DECLARE(void) pcscf_rx_send_aar(c_uint8_t **rx_sid, const char *ip,
        int qos_type, int flow_presence);
CORE_DECLARE(void) pcscf_rx_send_str(c_uint8_t *rx_sid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PCSCF_FD_PATH_H__ */

