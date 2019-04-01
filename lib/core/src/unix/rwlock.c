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
#include "core_rwlock.h"
#include "core_pool.h"
#include "core_debug.h"
#include "core_general.h"
#include "core_param.h"

typedef struct _rwlock_t {
    pthread_rwlock_t rwlock;
} rwlock_t;

pool_declare(rwlock_pool, rwlock_t, MAX_NUM_OF_RWLOCK);

status_t rwlock_init(void)
{
    pool_init(&rwlock_pool, MAX_NUM_OF_RWLOCK);
    return CORE_OK;
}

status_t rwlock_final(void)
{
    pool_final(&rwlock_pool);
    return CORE_OK;
}

status_t rwlock_create(rwlock_id *id)
{
    rwlock_t *new_rwlock;
    status_t stat;

    pool_alloc_node(&rwlock_pool, &new_rwlock);
    d_assert(new_rwlock, return CORE_ENOMEM, "rwlock_pool(%d) is not enough\n",
            MAX_NUM_OF_RWLOCK);

    if ((stat = pthread_rwlock_init(&new_rwlock->rwlock, NULL)))
    {
        return stat;
    }

    *id = (rwlock_id)new_rwlock;
    return CORE_OK;
}

status_t rwlock_rdlock(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_rdlock(&rwlock->rwlock);
    return stat;
}

status_t rwlock_tryrdlock(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_tryrdlock(&rwlock->rwlock);
    /* Normalize the return code. */
    if (stat == EBUSY)
        stat = CORE_EBUSY;
    return stat;
}

status_t rwlock_wrlock(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_wrlock(&rwlock->rwlock);
    return stat;
}

status_t rwlock_trywrlock(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_trywrlock(&rwlock->rwlock);
    /* Normalize the return code. */
    if (stat == EBUSY)
        stat = CORE_EBUSY;
    return stat;
}

status_t rwlock_unlock(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_unlock(&rwlock->rwlock);
    return stat;
}

status_t rwlock_delete(rwlock_id id)
{
    status_t stat;
    rwlock_t *rwlock = (rwlock_t *)id;

    stat = pthread_rwlock_destroy(&rwlock->rwlock);
    return stat;
}
