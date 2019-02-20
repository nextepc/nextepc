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


/*------------------------------------------------------------------------
 * ZUC.h
 * Code taken from the ZUC specification
 * available on the GSMA website
 *------------------------------------------------------------------------*/

#ifndef __ZUC_H__
#define __ZUC_H__

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* type definition from */
typedef c_uint8_t u8;
typedef c_uint32_t u32;

/*
 * ZUC keystream generator
 * k: secret key (input, 16 bytes)
 * iv: initialization vector (input, 16 bytes)
 * Keystream: produced keystream (output, variable length)
 * KeystreamLen: length in bits requested for the keystream (input)
*/
CORE_DECLARE(void) zuc_initialize(u8* k, u8* iv);
CORE_DECLARE(void) zuc_generate_key_stream(u32* pKeystream, u32 KeystreamLen);

/*
 * CK: ciphering key
 * COUNT: frame counter
 * BEARER: radio bearer
 * DIRECTION
 * LENGTH: length of the frame in bits
 * M: original message (input)
 * C: processed message (output)
*/
CORE_DECLARE(void) zuc_eea3(u8* CK, u32 COUNT, u32 BEARER, u32 DIRECTION, 
		           u32 LENGTH, u8* M, u8* C);

/*
 * IK: integrity key
 * COUNT: frame counter
 * BEARER: radio bearer
 * DIRECTION
 * LENGTH: length of the frame in bits
 * M: original message (input)
 * C: processed message (output)
*/
CORE_DECLARE(void) zuc_eia3(u8* IK, u32 COUNT, u32 BEARER, u32 DIRECTION,
		           u32 LENGTH, u8* M, u32* MAC);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ZUC_H__ */
