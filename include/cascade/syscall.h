// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_SYSCALL_H
#define _CASCADE_SYSCALL_H

#include <cascade/internal/defines.h>
#include <stdint.h>

typedef uint64_t cascade_syscall;

#define CASCADE_SYSCALL_THREAD_EXIT_CURRENT UINT64_C(0)

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__x86_64__)

_CASCADE_INLINE _CASCADE_NODISCARD int64_t cascade_syscall0(cascade_syscall syscall) {
    int64_t ret;
    __asm__ volatile("syscall" : "=a"(ret) : "a"(syscall) : "memory", "rcx", "r11");
    return ret;
}

#elif defined(__aarch64__)

// TODO: implement aarch64 syscalls
#error "unimplemented architecture"

#elif defined(__riscv)

// TODO: implement riscv syscalls
#error "unimplemented architecture"

#else
#error "unsupported architecture"
#endif

#ifdef __cplusplus
}
#endif

#endif // _CASCADE_SYSCALL_H
