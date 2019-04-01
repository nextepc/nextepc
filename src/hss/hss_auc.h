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


#ifndef __HSS_KDF_H__
#define __HSS_KDF_H__

#include "core.h"

#define HSS_SQN_LEN 6
#define HSS_AK_LEN 6

CORE_DECLARE(void) hss_auc_kasme(const c_uint8_t *ck, const c_uint8_t *ik, 
        const c_uint8_t plmn_id[3], const c_uint8_t *sqn,  const c_uint8_t *ak,
        c_uint8_t *kasme);

CORE_DECLARE(void) hss_auc_sqn(
    const c_uint8_t *opc, const c_uint8_t *k, const c_uint8_t *auts,
    c_uint8_t *sqn_ms, c_uint8_t *mac_s);

#endif /* __HSS_KDF_H__ */
