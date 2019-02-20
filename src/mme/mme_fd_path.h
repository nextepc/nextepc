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


#ifndef __MME_FD_PATH_H__
#define __MME_FD_PATH_H__

#include "core_errno.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) mme_fd_init(void);
CORE_DECLARE(void) mme_fd_final(void);

/* MME Sends Authentication Information Request to HSS */
CORE_DECLARE(void) mme_s6a_send_air(mme_ue_t *mme_ue,
    nas_authentication_failure_parameter_t *authentication_failure_parameter);
/* MME Sends Update Location Request to HSS */
CORE_DECLARE(void) mme_s6a_send_ulr(mme_ue_t *mme_ue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_FD_PATH_H__ */

