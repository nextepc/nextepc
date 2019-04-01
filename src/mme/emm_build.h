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


#ifndef __EMM_BUILD_H__
#define __EMM_BUILD_H__

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) emm_build_attach_accept(
        pkbuf_t **emmbuf, mme_ue_t *mme_ue, pkbuf_t *esmbuf);
CORE_DECLARE(status_t) emm_build_attach_reject(
        pkbuf_t **emmbuf, nas_emm_cause_t emm_cause, pkbuf_t *esmbuf);

CORE_DECLARE(status_t) emm_build_identity_request(
        pkbuf_t **emmbuf, mme_ue_t *mme_ue);
CORE_DECLARE(status_t) emm_build_security_mode_command(
        pkbuf_t **emmbuf, mme_ue_t *mme_ue);

CORE_DECLARE(status_t) emm_build_authentication_request(
        pkbuf_t **emmbuf, e_utran_vector_t *e_utran_vector);
CORE_DECLARE(status_t) emm_build_authentication_reject(pkbuf_t **emmbuf);

CORE_DECLARE(status_t) emm_build_detach_accept(
        pkbuf_t **emmbuf, mme_ue_t *mme_ue);

CORE_DECLARE(status_t) emm_build_tau_accept(pkbuf_t **emmbuf, mme_ue_t *mme_ue);
CORE_DECLARE(status_t) emm_build_tau_reject(pkbuf_t **emmbuf, 
        nas_emm_cause_t emm_cause,mme_ue_t *mme_ue);

CORE_DECLARE(status_t) emm_build_service_reject(pkbuf_t **emmbuf, 
        nas_emm_cause_t emm_cause, mme_ue_t *mme_ue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __EMM_BUILD_H__ */
