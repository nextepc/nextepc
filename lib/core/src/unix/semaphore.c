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


#include "core.h"
#include "core_arch_semaphore.h"
#include "core_errno.h"
#include "core_param.h"
#include "core_general.h"
#include "core_debug.h"
#include "core_pool.h"

pool_declare(semaphore_pool, semaphore_t, MAX_NUM_OF_SEMAPHORE);

status_t semaphore_init(void)
{
    pool_init(&semaphore_pool, MAX_NUM_OF_SEMAPHORE);
    return CORE_OK;
}

status_t semaphore_final(void)
{
    pool_final(&semaphore_pool);
    return CORE_OK;
}

status_t semaphore_create(semaphore_id *id, c_uint32_t value)
{
    semaphore_t *new_semaphore;
    c_time_t now = time_now();
    char semname[64];

    pool_alloc_node(&semaphore_pool, &new_semaphore);
    d_assert(new_semaphore, return CORE_ENOMEM,
            "semaphore_pool(%d) is not enough\n",
            MAX_NUM_OF_SEMAPHORE);

    sprintf(semname, "/CoRe%" C_UINT64_T_HEX_FMT, now);

    new_semaphore->semaphore = sem_open(semname, O_CREAT | O_EXCL, 0644, value);
    if (new_semaphore->semaphore == (sem_t *)SEM_FAILED)
    {
        return CORE_ERROR;
    }

    sem_unlink(semname);

    *id = (semaphore_id)new_semaphore;
    return CORE_OK;
}

status_t semaphore_wait(semaphore_id id)
{
    status_t rv;
    semaphore_t *semaphore = (semaphore_t *)id;

    rv = sem_wait(semaphore->semaphore);
    return rv;
}

#if HAVE_SEM_TIMEDWAIT
status_t semaphore_timedwait(semaphore_id id, c_time_t timeout)
{
    status_t rv;
    c_time_t then;
    struct timespec abstime;
    semaphore_t *semaphore = (semaphore_t *)id;

    then = time_now() + timeout;
    abstime.tv_sec = time_sec(then);
    abstime.tv_nsec = time_usec(then) * 1000; /* nanosesemaphores */

    rv = sem_timedwait(semaphore->semaphore, &abstime);
    if (rv == -1 && ETIMEDOUT == errno)
    {
        return CORE_TIMEUP;
    }
    return rv;
}
#endif

status_t semaphore_post(semaphore_id id)
{
    status_t rv;
    semaphore_t *semaphore = (semaphore_t *)id;

    rv = sem_post(semaphore->semaphore);
    return rv;
}

status_t semaphore_delete(semaphore_id id)
{
    status_t rv;
    semaphore_t *semaphore = (semaphore_t *)id;

    rv = sem_close(semaphore->semaphore);
    pool_free_node(&semaphore_pool, semaphore);

    return rv;
}
