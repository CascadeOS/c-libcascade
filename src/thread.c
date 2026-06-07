// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#include <cascade/internal/defines.h>

#include <cascade/syscall.h>
#include <cascade/thread.h>

_CASCADE_NORETURN void cascade_thread_exit_current(void) {
    (void)cascade_syscall0(CASCADE_SYSCALL_THREAD_EXIT_CURRENT);
    _CASCADE_UNREACHABLE();
}
