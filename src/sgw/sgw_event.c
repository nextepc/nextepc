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


#define TRACE_MODULE _sgw_event

#include "sgw_event.h"
#include "sgw_context.h"

char* sgw_event_get_name(event_t *e)
{
    if (e == NULL)
        return FSM_NAME_INIT_SIG;

    switch (event_get(e))
    {
        case FSM_ENTRY_SIG: 
            return FSM_NAME_ENTRY_SIG;
        case FSM_EXIT_SIG: 
            return FSM_NAME_EXIT_SIG;

        case SGW_EVT_S11_MESSAGE:
            return "SGW_EVT_S11_MESSAGE";
        case SGW_EVT_S5C_MESSAGE:
            return "SGW_EVT_S5C_MESSAGE";

        case SGW_EVT_T3_RESPONSE:
            return "SGW_EVT_T3_RESPONSE";
        case SGW_EVT_T3_HOLDING:
            return "SGW_EVT_T3_HOLDING";

        default: 
           break;
    }

    return EVT_NAME_UNKNOWN;
}
