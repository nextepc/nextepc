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


#ifndef __APP_INIT_H__
#define __APP_INIT_H__

#include "core.h"
#include "core_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) app_initialize(
        const char *config_path, const char *log_path, const char *pid_path);
CORE_DECLARE(void) app_terminate(void);

CORE_DECLARE(status_t) mme_initialize();
CORE_DECLARE(void) mme_terminate(void);

CORE_DECLARE(status_t) hss_initialize();
CORE_DECLARE(void) hss_terminate(void);

CORE_DECLARE(status_t) sgw_initialize();
CORE_DECLARE(void) sgw_terminate(void);

CORE_DECLARE(status_t) pgw_initialize();
CORE_DECLARE(void) pgw_terminate(void);

CORE_DECLARE(status_t) pcrf_initialize();
CORE_DECLARE(void) pcrf_terminate(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __APP_INIT_H__ */
