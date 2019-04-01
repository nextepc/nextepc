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


#ifndef __MME_EVENT_H__
#define __MME_EVENT_H__

#include "core_event.h"
#include "core_fsm.h"
#include "core_pkbuf.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* forward declaration */
typedef enum {
    MME_EVT_BASE = FSM_USER_SIG,

    MME_EVT_S1AP_MESSAGE,
    MME_EVT_S1AP_DELAYED_SEND,
    MME_EVT_S1AP_LO_ACCEPT,
    MME_EVT_S1AP_LO_SCTP_COMM_UP,
    MME_EVT_S1AP_LO_CONNREFUSED,
    MME_EVT_S1AP_S1_HOLDING_TIMER,

    MME_EVT_EMM_MESSAGE,
    MME_EVT_EMM_T3413,

    MME_EVT_ESM_MESSAGE,

    MME_EVT_S11_MESSAGE,
    MME_EVT_S11_T3_RESPONSE,
    MME_EVT_S11_T3_HOLDING,

    MME_EVT_S6A_MESSAGE,

    MME_EVT_TOP,

} event_e;

#define mme_event_send(__ptr_e) event_send(mme_self()->queue_id, (__ptr_e))

CORE_DECLARE(char*) mme_event_get_name(event_t *e);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_EVENT_H__ */
