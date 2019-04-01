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


#ifndef __SGW_PATH_H__
#define __SGW_PATH_H__

#include "gtp/gtp_xact.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) sgw_gtp_open();
CORE_DECLARE(status_t) sgw_gtp_close();

CORE_DECLARE(status_t) sgw_gtp_send_end_marker(sgw_tunnel_t *s1u_tunnel);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SGW_PATH_H__ */
