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


/*
 * UMTS AKA - Milenage algorithm (3GPP TS 35.205, .206, .207, .208)
 * Copyright (c) 2006-2007 <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef __MILENAGE_H__
#define __MILENAGE_H__

#include "core.h"

void milenage_generate(const c_uint8_t *opc, const c_uint8_t *amf, 
    const c_uint8_t *k, const c_uint8_t *sqn, const c_uint8_t *_rand, 
    c_uint8_t *autn, c_uint8_t *ik, c_uint8_t *ck, c_uint8_t *ak,
    c_uint8_t *res, size_t *res_len);
int milenage_auts(const c_uint8_t *opc, const c_uint8_t *k, 
    const c_uint8_t *_rand, const c_uint8_t *auts, c_uint8_t *sqn);
int gsm_milenage(const c_uint8_t *opc, const c_uint8_t *k, 
    const c_uint8_t *_rand, c_uint8_t *sres, c_uint8_t *kc);
int milenage_check(const c_uint8_t *opc, const c_uint8_t *k, 
    const c_uint8_t *sqn, const c_uint8_t *_rand, const c_uint8_t *autn, 
    c_uint8_t *ik, c_uint8_t *ck, c_uint8_t *res, size_t *res_len,
    c_uint8_t *auts);
int milenage_f1(const c_uint8_t *opc, const c_uint8_t *k, 
    const c_uint8_t *_rand, const c_uint8_t *sqn, const c_uint8_t *amf, 
    c_uint8_t *mac_a, c_uint8_t *mac_s);
int milenage_f2345(const c_uint8_t *opc, const c_uint8_t *k, 
    const c_uint8_t *_rand, c_uint8_t *res, c_uint8_t *ck, c_uint8_t *ik, 
    c_uint8_t *ak, c_uint8_t *akstar);

void milenage_opc(const c_uint8_t *k, const c_uint8_t *op,  c_uint8_t *opc);

#endif /* __MILENAGE_H__ */
