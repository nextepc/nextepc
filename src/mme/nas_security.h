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


#ifndef __NAS_SECURITY_H__
#define __NAS_SECURITY_H__

#include "core_pkbuf.h"
#include "core_aes.h"
#include "core_aes_cmac.h"

#include "mme_context.h"
#include "snow_3g.h"
#include "zuc.h"

#define NAS_SECURITY_BEARER 0
#define NAS_SECURITY_DOWNLINK_DIRECTION 1
#define NAS_SECURITY_UPLINK_DIRECTION 0

#define NAS_SECURITY_MAC_SIZE 4

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _nas_security_header_type_t {
    union {
        struct {
        ED5(c_uint8_t integrity_protected:1;,
            c_uint8_t ciphered:1;,
            c_uint8_t new_security_context:1;,
            c_uint8_t service_request:1;,
            c_uint8_t reserved:4;)
        };
        c_uint8_t type;
    };
} __attribute__ ((packed)) nas_security_header_type_t;

CORE_DECLARE(status_t) nas_security_encode(
        pkbuf_t **pkbuf, mme_ue_t *mme_ue, nas_message_t *message);
CORE_DECLARE(status_t) nas_security_decode(mme_ue_t *mme_ue, 
        nas_security_header_type_t security_header_type, pkbuf_t *pkbuf);

CORE_DECLARE(void) nas_mac_calculate(c_uint8_t algorithm_identity,
        c_uint8_t *knas_int, c_uint32_t count, c_uint8_t bearer, 
        c_uint8_t direction, pkbuf_t *pkbuf, c_uint8_t *mac);

CORE_DECLARE(void) nas_encrypt(c_uint8_t algorithm_identity,
        c_uint8_t *knas_enc, c_uint32_t count, c_uint8_t bearer, 
        c_uint8_t direction, pkbuf_t *pkbuf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __NAS_SECURITY_H__ */

