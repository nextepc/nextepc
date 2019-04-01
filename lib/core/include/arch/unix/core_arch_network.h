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


#ifndef __CORE_ARCH_NETWORK_H__
#define __CORE_ARCH_NETWORK_H__

#include "core_list.h"
#include "core_network.h"

#if HAVE_NETDB_H
#include <netdb.h>
#endif

#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#if HAVE_IFADDRS_H
#include <ifaddrs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _sock_t {
    lnode_t node;
    
    int family;

    int fd;
    char ifname[IFNAMSIZ];

    c_sockaddr_t local_addr;
    c_sockaddr_t remote_addr;

    sock_handler handler;
    void *data;

    c_int32_t options;
} sock_t;

#define sock_is_option_set(skt, option)  \
    (((skt)->options & (option)) == (option))

#define sock_set_option(skt, option, on) \
    do {                                 \
        if (on)                          \
            (skt)->options |= (option);         \
        else                             \
            (skt)->options &= ~(option);        \
    } while (0)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
