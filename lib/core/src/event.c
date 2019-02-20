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


/**
 * @file event.c
 */

/* Core libaray */
#define TRACE_MODULE _event
#include "core_debug.h"
#include "core_msgq.h"
#include "core_event.h"

#define EVT_Q_DEPTH 16

char *EVT_NAME_UNKNOWN = "UNKNOWN";

msgq_id event_create(int opt)
{
    msgq_id queue_id = 0;

    /* Start threads */
    queue_id = msgq_create(EVT_Q_DEPTH, EVENT_SIZE, opt);
    d_assert(queue_id != 0, return CORE_ERROR, "Message queue creation failed");

    return queue_id;
}

status_t event_delete(msgq_id queue_id)
{
    msgq_delete(queue_id);

    return CORE_OK;
}

status_t event_send(msgq_id queue_id, event_t *e)
{
    status_t rv;

    d_assert(e, return -1, "Null param");
    d_assert(queue_id, return -1, "event queue isn't initialized");

    rv = msgq_send(queue_id, (const char*)e, EVENT_SIZE);
    if (rv == CORE_EAGAIN)
    {
        d_warn("msgq_send full");
    } 
    else if (rv == CORE_ERROR)
    {
        d_error("msgq_send failed");
    }

    return rv;
}

status_t event_recv(msgq_id queue_id, event_t *e)
{
    status_t rv;

    d_assert(e, return -1, "Null param");
    d_assert(queue_id, return -1, "event queue isn't initialized");

    rv = msgq_recv(queue_id, (char*)e, EVENT_SIZE);
    if (rv == CORE_ERROR)
    {
        d_error("msgq_timedrecv failed", rv);
    }

    return rv;
}

status_t event_timedrecv(msgq_id queue_id, event_t *e, c_time_t timeout)
{
    status_t rv;

    d_assert(e, return -1, "Null param");
    d_assert(queue_id, return -1, "event queue isn't initialized");

    rv = msgq_timedrecv(queue_id, (char*)e, EVENT_SIZE, timeout);
    if (rv == CORE_ERROR)
    {
        d_error("msgq_timedrecv failed", rv);
    }

    return rv;
}

void* event_timer_expire_func(c_uintptr_t queue_id, c_uintptr_t param1,
        c_uintptr_t param2, c_uintptr_t param3, c_uintptr_t param4,
        c_uintptr_t param5, c_uintptr_t param6)
{
    event_t e;
    status_t rv;

    d_assert(queue_id, return NULL, "Null param");
    event_set(&e, param1);
    event_set_param1(&e, param2);
    event_set_param2(&e, param3);
    event_set_param3(&e, param4);
    event_set_param4(&e, param5);
    event_set_param5(&e, param6);

    rv = event_send(queue_id, &e);
    if (rv != CORE_OK)
    {
        d_error("event_send error:%d", rv);
    } 

    return NULL;
}

tm_block_id event_timer_create(tm_service_t *tm_service, tm_type_e type, 
        c_uint32_t duration, c_uintptr_t event)
{
    tm_block_id id;

    id = tm_create(tm_service,
            type, duration, (expire_func_t)event_timer_expire_func);
    tm_set_param1(id, event);
    d_assert(id, return 0, "tm_create() failed");

    return id;
}
