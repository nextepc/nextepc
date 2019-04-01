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


#ifndef __MME_PATH_H__
#define __MME_PATH_H__

#include "core_errno.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) mme_send_delete_session_or_detach(mme_ue_t *mme_ue);
CORE_DECLARE(status_t) mme_send_delete_session_or_ue_context_release(
        mme_ue_t *mme_ue, enb_ue_t *enb_ue);
CORE_DECLARE(status_t) mme_send_release_access_bearer_or_ue_context_release(
        mme_ue_t *mme_ue, enb_ue_t *enb_ue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_PATH_H__ */
