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


#define TRACE_MODULE _pcrf_fd_path

#include "core_debug.h"

#include "fd/fd_lib.h"

#include "pcrf_context.h"
#include "pcrf_fd_path.h"

status_t pcrf_fd_init(void)
{
    status_t rv;
    int ret = fd_init(FD_MODE_CLIENT|FD_MODE_SERVER,
                pcrf_self()->fd_conf_path, pcrf_self()->fd_config);
    d_assert(ret == 0, return CORE_ERROR,);

    rv = pcrf_gx_init();
    d_assert(rv == CORE_OK, return CORE_ERROR,);
    rv = pcrf_rx_init();
    d_assert(rv == CORE_OK, return CORE_ERROR,);

	return CORE_OK;
}

void pcrf_fd_final(void)
{
    pcrf_gx_final();
    pcrf_rx_final();

    fd_final();
}
