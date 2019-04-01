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


#ifndef __SBC_MESSAGE_H__
#define __SBC_MESSAGE_H__

#include "3gpp_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* SBc-AP messages:
 * After the CBC integration, the encoding/decoding of 
 * SBc-AP messages will be fully supported.
 */ 

/* SBc-AP interface data definitions */

/* SBc-AP WriteReplaceWarning data */
typedef struct _sbc_pws_data_t {
    c_uint16_t message_id;
    c_uint16_t serial_number;
    c_uint32_t no_of_tai;
    tai_t tai[16];              /* TODO: max 65535 */
    c_uint32_t repetition_period;
    c_uint32_t number_of_broadcast;
    c_uint8_t data_coding_scheme;
    c_uint32_t message_length;
    c_uint8_t message_contents[1024]; /* TODO: max 9600 */
} sbc_pws_data_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SBC_MESSAGE_H__ */
