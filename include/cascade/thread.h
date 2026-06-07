// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_THREAD_H
#define _CASCADE_THREAD_H

#include <stdint.h>

#include <cascade/internal/defines.h>

typedef struct { uint64_t handle; } cascade_thread_handle;

_CASCADE_STATIC_ASSERT(sizeof(cascade_thread_handle) == sizeof(uint64_t), "thread handle size mismatch");
_CASCADE_STATIC_ASSERT(_CASCADE_ALIGNOF(cascade_thread_handle) == _CASCADE_ALIGNOF(uint64_t), "thread handle alignment mismatch");

#ifdef __cplusplus
extern "C" {
#endif

_CASCADE_NORETURN void cascade_thread_exit_current(void);

#ifdef __cplusplus
}
#endif

#endif // _CASCADE_THREAD_H
