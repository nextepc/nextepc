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


#ifndef _CORE_AES_CMAC_H
#define _CORE_AES_CMAC_H

#include "core_aes.h"

#define AES_CMAC_DIGEST_LEN 16

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Caculate CMAC value
 *
 * @param cmac
 * @param key
 * @param msg
 * @param len
 *
 * @return CORE_OK
 *         CORE_ERROR
 */
CORE_DECLARE(status_t) aes_cmac_calculate(c_uint8_t *cmac, const c_uint8_t *key,
        const c_uint8_t *msg, const c_uint32_t len);

/**
 * Verify CMAC value
 *
 * @param cmac
 * @param key
 * @param msg
 * @param len
 *
 * @return CORE_OK
 *         CORE_ERROR
 *         ERR_INVALID_CMAC
 */
#define ERR_INVALID_CMAC -2
CORE_DECLARE(status_t) aes_cmac_verify(c_uint8_t *cmac, const c_uint8_t *key,
        const c_uint8_t *msg, const c_uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* ! _CORE_AES_CMAC_H */
