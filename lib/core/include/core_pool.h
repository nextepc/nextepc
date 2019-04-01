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


#ifndef __CORE_POOL_H__
#define __CORE_POOL_H__

#include "core.h"
#include "core_mutex.h"

#define pool_declare(__name, __type, __size) \
    typedef struct { \
        int head, tail; \
        int size, avail; \
        __type *free[__size], pool[__size]; \
        mutex_id mut; \
    } pool_##__name##_t; \
    pool_##__name##_t __name

#define pool_init(__pname, __size) do { \
    int __i; \
    mutex_create(&(__pname)->mut, MUTEX_DEFAULT); \
    (__pname)->size = (__pname)->avail = __size; \
    (__pname)->head = (__pname)->tail = 0; \
    for (__i = 0; __i < __size; __i++) \
        (__pname)->free[__i] = &((__pname)->pool[__i]); \
} while (0)

#define pool_final(__pname) \
    ((__pname)->mut ? mutex_delete((__pname)->mut) : CORE_OK)

#define pool_init_wo_lock(__pname, __size) do { \
    int __i; \
    (__pname)->mut = 0; \
    (__pname)->size = (__pname)->avail = __size; \
    (__pname)->head = (__pname)->tail = 0; \
    for (__i = 0; __i < __size; __i++) \
        (__pname)->free[__i] = &((__pname)->pool[__i]); \
} while (0)

#define pool_alloc_node(__pname, __pptr_node) do { \
    *(__pptr_node) = NULL; \
    if ((__pname)->mut) mutex_lock((__pname)->mut); \
    if ((__pname)->avail > 0) { \
         (__pname)->avail--; \
         *(__pptr_node) = (void*)(__pname)->free[(__pname)->head]; \
         (__pname)->free[(__pname)->head] = NULL; \
         (__pname)->head = ((__pname)->head + 1) % ((__pname)->size); \
    } \
    if ((__pname)->mut) mutex_unlock((__pname)->mut); \
} while (0)

#define pool_free_node(__pname, __ptr_node) do { \
    if ((__pname)->mut) mutex_lock((__pname)->mut); \
    if ((__pname)->avail < (__pname)->size) { \
        (__pname)->avail++; \
        (__pname)->free[(__pname)->tail] = (void*)(__ptr_node); \
        (__pname)->tail = ((__pname)->tail + 1) % ((__pname)->size); \
    } \
    if ((__pname)->mut) mutex_unlock((__pname)->mut); \
} while (0)

#define pool_size(__pname) ((__pname)->size)

#define pool_avail(__pname) ((__pname)->avail)

#define pool_used(__pname) (pool_size(__pname) - pool_avail(__pname))

#endif /* ! __CORE_POOL_H__ */
