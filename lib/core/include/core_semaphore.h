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


#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

/**
 * @file semaphore.h
 * @brief Core Mutex Routines
 */

#include "core.h"
#include "core_errno.h"
#include "core_time.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup semaphore Routines
 * @ingroup CORE
 * @{
 */

/** Opaque semaphore structure */
typedef c_uintptr_t semaphore_id;

/**
 * Initialize Mutex Pool
 */
CORE_DECLARE(status_t) semaphore_init(void);

/**
 * Finalize Mutex Pool
 */
CORE_DECLARE(status_t) semaphore_final(void);

/**
 * Create and initialize a semaphore that can be used to synchronize processes.
 * @param id the memory address where the newly created semaphore will be
 *        stored.
 * @value initial value for semaphore
 */
CORE_DECLARE(status_t) semaphore_create(semaphore_id *id, c_uint32_t value);
/**
 * Put the active calling thread to sleep until signaled to wake up.
 * @param id the semaphore variable on which to block.
 */
CORE_DECLARE(status_t) semaphore_wait(semaphore_id id);

#if HAVE_SEM_TIMEDWAIT
/**
 * Put the active calling thread to sleep until signaled to wake up or
 * the timeout is reached.
 * @param id the semaphore variable on which to block.
 * @param timeout The amount of time in microsesemaphores to wait. This is
 *        a maximum, not a minimum. If the semaphoreition is signaled, we
 *        will wake up before this time, otherwise the error CORE_TIMEUP
 *        is returned.
 */
CORE_DECLARE(status_t) semaphore_timedwait(semaphore_id id, c_time_t timeout);
#endif

/**
 * Posts a single thread, if one exists, that is blocking on the given
 * semaphore variable.
 * @param id the semaphore variable on which to produce the signal.
 */
CORE_DECLARE(status_t) semaphore_post(semaphore_id id);

/**
 * Destroy the semaphore and free the memory associated with the lock.
 * @param semaphore the semaphore to destroy.
 */
CORE_DECLARE(status_t) semaphore_delete(semaphore_id id);

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* ! __SEMAPHORE_H__ */
