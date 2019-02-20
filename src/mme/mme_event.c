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


#define TRACE_MODULE _mme_event

#include "core_debug.h"

#include "mme_event.h"

char* mme_event_get_name(event_t *e)
{
    if (e == NULL)
        return FSM_NAME_INIT_SIG;

    switch (event_get(e))
    {
        case FSM_ENTRY_SIG: 
            return FSM_NAME_ENTRY_SIG;
        case FSM_EXIT_SIG: 
            return FSM_NAME_EXIT_SIG;

        case MME_EVT_S1AP_MESSAGE:
            return "MME_EVT_S1AP_MESSAGE";
        case MME_EVT_S1AP_DELAYED_SEND:
            return "MME_EVT_S1AP_DELAYED_SEND";
        case MME_EVT_S1AP_LO_ACCEPT:
            return "MME_EVT_S1AP_LO_ACCEPT";
        case MME_EVT_S1AP_LO_SCTP_COMM_UP:
            return "MME_EVT_S1AP_LO_SCTP_COMM_UP";
        case MME_EVT_S1AP_LO_CONNREFUSED:
            return "MME_EVT_S1AP_LO_CONNREFUSED";
        case MME_EVT_S1AP_S1_HOLDING_TIMER:
            return "MME_EVT_S1AP_S1_HOLDING_TIMER";

        case MME_EVT_EMM_MESSAGE:
            return "MME_EVT_EMM_MESSAGE";
        case MME_EVT_EMM_T3413:
            return "MME_EVT_EMM_T3413";

        case MME_EVT_ESM_MESSAGE:
            return "MME_EVT_ESM_MESSAGE";

        case MME_EVT_S11_MESSAGE:
            return "MME_EVT_S11_MESSAGE";
        case MME_EVT_S11_T3_RESPONSE:
            return "MME_EVT_S11_T3_RESPONSE";
        case MME_EVT_S11_T3_HOLDING:
            return "MME_EVT_S11_T3_HOLDING";

        case MME_EVT_S6A_MESSAGE:
            return "MME_EVT_S6A_MESSAGE";

        default: 
           break;
    }

    return EVT_NAME_UNKNOWN;
}
