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


#ifndef __PCRF_CONTEXT_H__
#define __PCRF_CONTEXT_H__

#include "core_errno.h"
#include "core_mutex.h"
#include "core_hash.h"

#include "3gpp_types.h"
#include "fd/gx/gx_message.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _fd_config_t fd_config_t;
struct session;

typedef struct _pcrf_context_t {
    const char      *fd_conf_path;  /* PCRF freeDiameter conf path */
    fd_config_t     *fd_config;     /* PCRF freeDiameter config */

    void            *subscriberCollection;
    mutex_id        db_lock;

    hash_t          *ip_hash; /* hash table for Gx Frame IPv4/IPv6 */
    mutex_id        hash_lock;
} pcrf_context_t;

CORE_DECLARE(status_t) pcrf_context_init(void);
CORE_DECLARE(status_t) pcrf_context_final(void);
CORE_DECLARE(pcrf_context_t*) pcrf_self(void);

CORE_DECLARE(status_t) pcrf_context_parse_config(void);
CORE_DECLARE(status_t) pcrf_context_setup_trace_module(void);

CORE_DECLARE(status_t) pcrf_db_init(void);
CORE_DECLARE(status_t) pcrf_db_final(void);

CORE_DECLARE(status_t) pcrf_db_qos_data(
        c_int8_t *imsi_bcd, c_int8_t *apn, gx_message_t *gx_message);

CORE_DECLARE(status_t) pcrf_sess_set_ipv4(const void *key, c_uint8_t *sid);
CORE_DECLARE(status_t) pcrf_sess_set_ipv6(const void *key, c_uint8_t *sid);
CORE_DECLARE(c_uint8_t *) pcrf_sess_find_by_ipv4(const void *key);
CORE_DECLARE(c_uint8_t *) pcrf_sess_find_by_ipv6(const void *key);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PCRF_CONTEXT_H__ */
