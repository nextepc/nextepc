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


#define TRACE_MODULE _pcrf_init

#include "pcrf_context.h"
#include "pcrf_fd_path.h"

static int initialized = 0;

status_t pcrf_initialize(void)
{
    status_t rv;

    rv = pcrf_context_init();
    if (rv != CORE_OK) return rv;

    rv = pcrf_context_parse_config();
    if (rv != CORE_OK) return rv;

    rv = pcrf_context_setup_trace_module();
    if (rv != CORE_OK) return rv;

    rv = pcrf_db_init();
    if (rv != CORE_OK) return rv;

    rv = pcrf_fd_init();
    if (rv != CORE_OK) return CORE_ERROR;

    initialized = 1;

	return CORE_OK;
}

void pcrf_terminate(void)
{
    if (!initialized) return;

    pcrf_fd_final();

    pcrf_db_final();
    pcrf_context_final();
	
	return;
}
