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


#ifndef CORE_SIGNAL_H
#define CORE_SIGNAL_H

/**
 * @file core_signal.h
 * @brief CORE Signal Handling
 */

#include "core.h"
#include "core_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup core_signal Signal Handling
 * @ingroup CORE
 * @{
 */

/** 
 * Terminate a process.
 * @param proc The process to terminate.
 * @param sig How to kill the process.
 */
CORE_DECLARE(status_t) core_kill(pid_t pid, int sig);

#if HAVE_SIGACTION

#if defined(DARWIN) && !defined(__cplusplus) && !defined(_ANSI_SOURCE)
/* work around Darwin header file bugs
 *   http://www.opensource.apple.com/bugs/X/BSD%20Kernel/2657228.html
 */
#undef SIG_DFL
#undef SIG_IGN
#undef SIG_ERR
#define SIG_DFL (void (*)(int))0
#define SIG_IGN (void (*)(int))1
#define SIG_ERR (void (*)(int))-1
#endif

/** Function prototype for signal handlers */
typedef void core_sigfunc_t(int);

/**
 * Set the signal handler function for a given signal
 * @param signo The signal (eg... SIGWINCH)
 * @param func the function to get called
 */
CORE_DECLARE(core_sigfunc_t *) core_signal(int signo, core_sigfunc_t * func);

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((core_sigfunc_t *) -1)
#endif

#else /* !HAVE_SIGACTION */
#define core_signal(a, b) signal(a, b)
#endif


/**
 * Setup the process for a single thread to be used for all signal handling.
 * @warning This must be called before any threads are created
 */
CORE_DECLARE(status_t) signal_init(void);

/**
 * Make the current thread listen for signals.  This thread will loop
 * forever, calling a provided function whenever it receives a signal.  That
 * functions should return 1 if the signal has been handled, 0 otherwise.
 * @param signal_handler The function to call when a signal is received
 * apr_status_t apr_signal_thread((int)(*signal_handler)(int signum))
 */
CORE_DECLARE(status_t) signal_thread(int(*signal_handler)(int signum));

/**
 * Block the delivery of a particular signal
 * @param signum The signal number
 * @return status
 */
CORE_DECLARE(status_t) signal_block(int signum);

/**
 * Enable the delivery of a particular signal
 * @param signum The signal number
 * @return status
 */
CORE_DECLARE(status_t) signal_unblock(int signum);

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CORE_SIGNAL_H */
