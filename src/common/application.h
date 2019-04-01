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


#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"
#include "core_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) app_will_initialize(
        const char *config_path, const char *log_path);
CORE_DECLARE(status_t) app_did_initialize(void);
CORE_DECLARE(void) app_will_terminate(void);
CORE_DECLARE(void) app_did_terminate(void);

CORE_DECLARE(status_t) config_initialize(const char *config_path);
CORE_DECLARE(void) config_terminate(void);

CORE_DECLARE(status_t) app_logger_restart(void);
CORE_DECLARE(status_t) app_log_pid(const char *pid_path, const char *app_name);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __APPLICATION_H__ */
