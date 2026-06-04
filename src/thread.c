// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#include <cascade/defines.h>
#include <cascade/syscall.h>
#include <cascade/thread.h>

CASCADE_NORETURN void cascade_exit_current_thread(void) {
    (void)cascade_syscall0(CASCADE_SYSCALL_EXIT_CURRENT_THREAD);
    CASCADE_UNREACHABLE();
}
