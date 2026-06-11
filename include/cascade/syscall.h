// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_SYSCALL_H
#define _CASCADE_SYSCALL_H

#include <cascade/internal/defines.h>
#include <stdint.h>

typedef uint64_t cascade_syscall;

/**
 * Exits the current thread.
 *
 * ### Arguments
 * none
 *
 * ### Errors
 * none
 *
 * ### Return
 * never
 */
#define CASCADE_SYSCALL_THREAD_EXIT_CURRENT ((cascade_syscall)0)

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__x86_64__)

_CASCADE_INLINE int64_t cascade_syscall0(cascade_syscall syscall) {
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
