// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#include <cascade/internal/common.h>
#include <cascade/syscall.h>
#include <cascade/thread.h>

_CASCADE_NORETURN void cascade_thread_exit_current(void) {
    (void)cascade_syscall0(CASCADE_SYSCALL_THREAD_EXIT_CURRENT);
    _CASCADE_UNREACHABLE();
}

_CASCADE_STATIC_ASSERT(sizeof(cascade_thread_handle) == sizeof(uint64_t), "thread handle size mismatch");
_CASCADE_STATIC_ASSERT(_CASCADE_ALIGNOF(cascade_thread_handle) == _CASCADE_ALIGNOF(uint64_t), "thread handle alignment mismatch");
