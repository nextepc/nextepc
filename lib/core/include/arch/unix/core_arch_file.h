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


#ifndef __CORE_ARCH_FILE_H__
#define __CORE_ARCH_FILE_H__

#include "core_portable.h"
#include "core_time.h"
#include "core_file.h"

#define FILE_DEFAULT_BUFSIZE 4096
/* For backwards-compat */
#define FILE_BUFSIZE  FILE_DEFAULT_BUFSIZE

struct file_t {
    os_file_t filedes;
    char fname[MAX_FILENAME_SIZE];
    c_int32_t flags;
    int eof_hit;
    c_time_t timeout;
    off_t filePtr;              /* position in file of handle */
};

typedef struct stat struct_stat;

mode_t unix_perms2mode(file_perms_t perms);
file_perms_t unix_mode2perms(mode_t mode);

#endif  /* ! __CORE_ARCH_FILE_H__ */

