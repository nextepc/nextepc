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


#ifndef __NAS_CONV_H__
#define __NAS_CONV_H__

#include "nas/nas_message.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) nas_imsi_to_buffer(
    nas_mobile_identity_imsi_t *imsi, c_uint8_t imsi_len, 
    c_uint8_t *buf, c_uint8_t *buf_len);

CORE_DECLARE(void) nas_imsi_to_bcd(
    nas_mobile_identity_imsi_t *imsi, c_uint8_t imsi_len, c_int8_t *bcd);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __NAS_CONV_H__ */

