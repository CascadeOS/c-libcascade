// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#include <cascade/debug.h>
#include <cascade/internal/defines.h>
#include <cascade/syscall.h>

void cascade_debug_print(uint64_t len, const uint8_t buf[_CASCADE_ARRAY_LEN(len)]) {
    (void)cascade_syscall2(CASCADE_SYSCALL_DEBUG_PRINT, len, (uint64_t)buf);
}
