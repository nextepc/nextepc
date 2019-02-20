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


#define TRACE_MODULE _udp

#include "core_debug.h"
#include "core_arch_network.h"

status_t udp_socket(sock_id *new, int family)
{
    status_t rv;

    rv = sock_socket(new, family, SOCK_DGRAM, IPPROTO_UDP);
    d_assert(rv == CORE_OK && new, return CORE_ERROR,);

    d_trace(1, "udp socket(%d)\n", family);

    return CORE_OK;
}

status_t udp_server(sock_id *new, c_sockaddr_t *sa_list)
{
    status_t rv;
    c_sockaddr_t *addr;
    char buf[CORE_ADDRSTRLEN];

    d_assert(new, return CORE_ERROR,);
    d_assert(sa_list, return CORE_ERROR,);

    addr = sa_list;
    while(addr)
    {
        rv = udp_socket(new, addr->c_sa_family);
        if (rv == CORE_OK)
        {
            d_assert(sock_setsockopt(*new, SOCK_O_REUSEADDR, 1) == CORE_OK,
                    return CORE_ERROR,
                    "setsockopt [%s]:%d failed(%d:%s)",
                    CORE_ADDR(addr, buf), CORE_PORT(addr),
                    errno, strerror(errno));

            if (sock_bind(*new, addr) == CORE_OK)
            {
                d_trace(1, "udp_server() [%s]:%d\n",
                        CORE_ADDR(addr, buf), CORE_PORT(addr));
                break;
            }

            rv = sock_delete(*new);
            d_assert(rv == CORE_OK, return CORE_ERROR,);
        }

        addr = addr->next;
    }

    if (addr == NULL)
    {
        d_error("udp_server() [%s]:%d failed(%d:%s)",
                CORE_ADDR(sa_list, buf), CORE_PORT(sa_list),
                errno, strerror(errno));
        return CORE_ERROR;
    }

    return CORE_OK;
}

status_t udp_client(sock_id *new, c_sockaddr_t *sa_list)
{
    status_t rv;
    c_sockaddr_t *addr;
    char buf[CORE_ADDRSTRLEN];

    d_assert(new, return CORE_ERROR,);
    d_assert(sa_list, return CORE_ERROR,);

    addr = sa_list;
    while(addr)
    {
        rv = udp_socket(new, addr->c_sa_family);
        if (rv == CORE_OK)
        {
            if (sock_connect(*new, addr) == CORE_OK)
            {
                d_trace(1, "udp_client() [%s]:%d\n",
                        CORE_ADDR(addr, buf), CORE_PORT(addr));
                break;
            }

            rv = sock_delete(*new);
            d_assert(rv == CORE_OK, return CORE_ERROR,);
        }

        addr = addr->next;
    }

    if (addr == NULL)
    {
        d_error("udp_client() [%s]:%d failed(%d:%s)",
                CORE_ADDR(sa_list, buf), CORE_PORT(sa_list), errno,
                strerror(errno));
        return CORE_ERROR;
    }

    return CORE_OK;
}

status_t udp_connect(sock_id id, c_sockaddr_t *sa_list)
{
    c_sockaddr_t *addr;
    char buf[CORE_ADDRSTRLEN];

    d_assert(id, return CORE_ERROR,);
    d_assert(sa_list, return CORE_ERROR,);

    addr = sa_list;
    while(addr)
    {
        if (sock_connect(id, addr) == CORE_OK)
        {
            d_trace(1, "udp_connect() [%s]:%d\n",
                    CORE_ADDR(addr, buf), CORE_PORT(addr));
            break;
        }

        addr = addr->next;
    }

    if (addr == NULL)
    {
        d_error("udp_connect() [%s]:%d failed(%d:%s)",
                CORE_ADDR(sa_list, buf), CORE_PORT(sa_list),
                errno, strerror(errno));
        return CORE_ERROR;
    }

    return CORE_OK;
}
