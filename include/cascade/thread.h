// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_THREAD_H
#define _CASCADE_THREAD_H

#include <cascade/internal/defines.h>
#include <stdint.h>

typedef struct {
    uint64_t handle;
} cascade_thread_handle;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Exits the current thread.
 */
_CASCADE_NORETURN void cascade_thread_exit_current(void);

#ifdef __cplusplus
}
#endif

#endif // _CASCADE_THREAD_H
