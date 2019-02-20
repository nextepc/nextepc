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


#include "core_pkbuf.h"
#include "testutil.h"

static void pkbuf_test1(abts_case *tc, void *data)
{
    char *ptr = core_malloc(256);
    ABTS_PTR_NOTNULL(tc, ptr);
    CORE_FREE(ptr);
}

static void pkbuf_test2(abts_case *tc, void *data)
{
    char *ptr = core_calloc(2, 10);
    int i;
    for (i = 0; i < 2*10; i++)
    {
        ABTS_INT_EQUAL(tc, 0, ptr[i]);
    }
    ABTS_PTR_NOTNULL(tc, ptr);
    CORE_FREE(ptr);
}

static void pkbuf_test3(abts_case *tc, void *data)
{
    char *ptr = core_realloc(0, 10);
    ABTS_PTR_NOTNULL(tc, ptr);
    CORE_FREE(ptr);

    ptr = core_malloc(20);
    ABTS_PTR_NOTNULL(tc, ptr);
    ptr = core_realloc(ptr, 0);
}

static void pkbuf_test4(abts_case *tc, void *data)
{
    char *p, *q;

    p = core_malloc(10);
    ABTS_PTR_NOTNULL(tc, p);
    memset(p, 1, 10);

    q = core_realloc(p, 
            CORE_ALIGN(128+MAX_SIZEOF_HEADROOM, SIZEOF_VOIDP) - 
            SIZEOF_VOIDP-1);
    ABTS_TRUE(tc, p == q);

    p = core_realloc(q, 
            CORE_ALIGN(128+MAX_SIZEOF_HEADROOM, SIZEOF_VOIDP) - 
            SIZEOF_VOIDP);
    ABTS_TRUE(tc, p != q);
    ABTS_TRUE(tc, memcmp(p, q, 10) == 0);
    CORE_FREE(p);
}


abts_suite *testpkbuf(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, pkbuf_test1, NULL);
    abts_run_test(suite, pkbuf_test2, NULL);
    abts_run_test(suite, pkbuf_test3, NULL);
    abts_run_test(suite, pkbuf_test4, NULL);

    return suite;
}
