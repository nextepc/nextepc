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


#include "core_errno.h"

#define DEV_RANDOM "/dev/urandom"

status_t core_generate_random_bytes(c_uint8_t *buf, int length)
{
    int fd = -1;

    /* On BSD/OS 4.1, /dev/random gives out 8 bytes at a time, then
     * gives EOF, so reading 'length' bytes may require opening the
     * device several times. */
    do {
        int rc;

        if (fd == -1)
            if ((fd = open(DEV_RANDOM, O_RDONLY)) == -1)
                return errno;
        
        do {
            rc = read(fd, buf, length);
        } while (rc == -1 && errno == EINTR);

        if (rc < 0) {
            int errnum = errno;
            close(fd);
            return errnum;
        }
        else if (rc == 0) {
            close(fd);
            fd = -1; /* force open() again */
        }
        else {
            buf += rc;
            length -= rc;
        }
    } while (length > 0);
    
    close(fd);

    return CORE_OK;
}
