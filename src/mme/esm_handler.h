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


#ifndef __ESM_HANDLER_H__
#define __ESM_HANDLER_H__

#include "nas/nas_message.h"

#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) esm_handle_pdn_connectivity_request(mme_bearer_t *bearer,
        nas_pdn_connectivity_request_t *pdn_connectivity_request);
CORE_DECLARE(status_t) esm_handle_information_response(mme_sess_t *sess, 
        nas_esm_information_response_t *bearer_information_response);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ESM_HANDLER_H__ */
