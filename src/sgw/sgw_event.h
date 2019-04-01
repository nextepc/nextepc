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


#ifndef __SGW_EVENT_H__
#define __SGW_EVENT_H__

#include "core_event.h"
#include "core_fsm.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    SGW_EVT_BASE = FSM_USER_SIG,

    SGW_EVT_S11_MESSAGE,
    SGW_EVT_S5C_MESSAGE,

    SGW_EVT_T3_RESPONSE,
    SGW_EVT_T3_HOLDING,

    SGW_EVT_LO_DLDATA_NOTI,

    SGW_EVT_TOP,

} event_e;

#define sgw_event_send(__ptr_e) event_send(sgw_self()->queue_id, (__ptr_e))

CORE_DECLARE(char*) sgw_event_get_name(event_t *e);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SGW_EVENT_H__ */
