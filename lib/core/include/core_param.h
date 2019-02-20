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


#ifndef __CORE_PARAM_H__
#define __CORE_PARAM_H__

#define MAX_NUM_OF_THREAD       128
#define MAX_NUM_OF_THREADATTR  MAX_NUM_OF_THREAD
#define MAX_NUM_OF_PROC         128
#define MAX_NUM_OF_MUTEX        512
#define MAX_NUM_OF_COND         512
#define MAX_NUM_OF_RWLOCK       512
#define MAX_NUM_OF_SEMAPHORE    512

#define MAX_NUM_OF_FILE         256
#define MAX_FILENAME_SIZE       256
#define MAX_DIRNAME_SIZE        256

#define MAX_NUM_OF_TIMER        1024

#define MAX_SIG_DESC_SIZE       256

#define HUGE_STRING_LEN         8192
#define MAX_FILEPATH_LEN        256
#define MAX_ERROR_STRING_LEN    1024

#endif /* ! __CORE_PARAM_H__ */
