// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef CASCADE_THREAD_H
#define CASCADE_THREAD_H

#include <stdint.h>

#include <cascade/defines.h>

typedef struct { uint64_t handle; } cascade_thread_handle;

CASCADE_STATIC_ASSERT(sizeof(cascade_thread_handle) == sizeof(uint64_t), "thread handle size mismatch");
CASCADE_STATIC_ASSERT(CASCADE_ALIGNOF(cascade_thread_handle) == CASCADE_ALIGNOF(uint64_t), "thread handle alignment mismatch");

#ifdef __cplusplus
extern "C" {
#endif

CASCADE_NORETURN void cascade_exit_current_thread(void);

#ifdef __cplusplus
}
#endif

#endif // CASCADE_THREAD_H
