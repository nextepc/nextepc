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


/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "core_time.h"
#include "testutil.h"

#define SLEEP_INTERVAL 3

static void sleep_one(abts_case *tc, void *data)
{
    time_t pretime = time(NULL);
    time_t posttime;
    time_t timediff;

    core_sleep(time_from_sec(SLEEP_INTERVAL));
    posttime = time(NULL);

    /* normalize the timediff.  We should have slept for SLEEP_INTERVAL, so
     * we should just subtract that out.
     */
    timediff = posttime - pretime - SLEEP_INTERVAL;
    ABTS_TRUE(tc, timediff >= 0);
    ABTS_TRUE(tc, timediff <= 1);
}

abts_suite *testsleep(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, sleep_one, NULL);

    return suite;
}

