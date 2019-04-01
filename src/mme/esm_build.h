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


#ifndef __ESM_BUILD_H__
#define __ESM_BUILD_H__

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) esm_build_pdn_connectivity_reject(pkbuf_t **pkbuf,
                            mme_sess_t *sess, nas_esm_cause_t esm_cause);
CORE_DECLARE(status_t) esm_build_information_request(pkbuf_t **pkbuf,
                            mme_bearer_t *bearer);
CORE_DECLARE(status_t) esm_build_activate_default_bearer_context_request(
                            pkbuf_t **pkbuf, mme_sess_t *sess);
CORE_DECLARE(status_t) esm_build_activate_dedicated_bearer_context_request(
                            pkbuf_t **pkbuf, mme_bearer_t *bearer);
CORE_DECLARE(status_t) esm_build_modify_bearer_context_request(
        pkbuf_t **pkbuf, mme_bearer_t *bearer, int qos_presence, int tft_presence);
CORE_DECLARE(status_t) esm_build_deactivate_bearer_context_request(
        pkbuf_t **pkbuf, mme_bearer_t *bearer, nas_esm_cause_t esm_cause);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ESM_BUILD_H__ */
