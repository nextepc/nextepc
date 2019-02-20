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


#ifndef __MME_S6A_HANDLER_H__
#define __MME_S6A_HANDLER_H__

#include "fd/s6a/s6a_message.h"
#include "mme_context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) mme_s6a_handle_aia(
        mme_ue_t *mme_ue, s6a_aia_message_t *aia_message);
CORE_DECLARE(void) mme_s6a_handle_ula(
        mme_ue_t *mme_ue, s6a_ula_message_t *ula_message);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_S6A_HANDLER_H__ */
