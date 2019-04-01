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


#ifndef __CORE_ARCH_PROC_H__
#define __CORE_ARCH_PROC_H__

#include "core_proc.h"
#include "core_semaphore.h"

typedef struct _proc_t {
    pid_t proc;
    void *data;
    proc_func_t start_func;
    proc_func_t stop_func;
    status_t exitval;

    semaphore_id sem1;
    semaphore_id sem2;
} proc_t;

#endif  /* __CORE_ARCH_PROC_H__ */

