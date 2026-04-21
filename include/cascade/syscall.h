// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef CASCADE_SYSCALL_H
#define CASCADE_SYSCALL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t cascade_syscall_t;

#define CASCADE_SYSCALL_EXIT_CURRENT_THREAD UINT64_C(0)

#if defined(__GNUC__) || defined(__clang__)
    #define CASCADE_INLINE static inline __attribute__((always_inline))
#else
    #define CASCADE_INLINE static inline
#endif

#if defined(__x86_64__)

CASCADE_INLINE int64_t cascade_syscall0(cascade_syscall_t syscall)
{
    int64_t ret;
    asm volatile("syscall" : "=a"(ret) : "D"(syscall) : "memory", "rcx", "r11");
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

#endif // CASCADE_SYSCALL_H
