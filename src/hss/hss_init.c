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


#define TRACE_MODULE _hss_init

#include "hss_context.h"
#include "hss_fd_path.h"

static int initialized = 0;

status_t hss_initialize(void)
{
    status_t rv;

    rv = hss_context_init();
    if (rv != CORE_OK) return rv;

    rv = hss_context_parse_config();
    if (rv != CORE_OK) return rv;

    rv = hss_context_setup_trace_module();
    if (rv != CORE_OK) return rv;

    rv = hss_db_init();
    if (rv != CORE_OK) return rv;

    rv = hss_fd_init();
    if (rv != CORE_OK) return CORE_ERROR;

    initialized = 1;

	return CORE_OK;
}

void hss_terminate(void)
{
    if (!initialized) return;

    hss_fd_final();

    hss_db_final();
    hss_context_final();
	
	return;
}
