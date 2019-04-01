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


#ifndef __CORE_ARCH_MUTEX_H__
#define __CORE_ARCH_MUTEX_H__

#include "core.h"
#include "core_mutex.h"

typedef struct _mutex_t {
    pthread_mutex_t mutex;
} mutex_t;

#endif  /* __CORE_ARCH_MUTEX_H__ */

