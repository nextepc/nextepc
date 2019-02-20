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


#include "core_version.h"
#include "core_general.h" /* for CORE_STRINGIFY */

CORE_DECLARE(void) core_version(core_version_t *pvsn)
{
    pvsn->major = CORE_MAJOR_VERSION;
    pvsn->minor = CORE_MINOR_VERSION;
    pvsn->patch = CORE_PATCH_VERSION;
#ifdef CORE_IS_DEV_VERSION
    pvsn->is_dev = 1;
#else
    pvsn->is_dev = 0;
#endif
}

CORE_DECLARE(const char *) core_version_string(void)
{
    return CORE_VERSION_STRING;
}
