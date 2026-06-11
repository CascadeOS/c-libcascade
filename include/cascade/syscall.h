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

_CASCADE_INLINE int64_t cascade_syscall1(cascade_syscall syscall, uint64_t arg1) {
    int64_t ret;
    __asm__ volatile("syscall" : "=a"(ret) : "a"(syscall), "D"(arg1) : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall2(cascade_syscall syscall, uint64_t arg1, uint64_t arg2) {
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall), "D"(arg1), "S"(arg2)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t
cascade_syscall3(cascade_syscall syscall, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall), "D"(arg1), "S"(arg2), "d"(arg3)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall4(
    cascade_syscall syscall, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall), "D"(arg1), "S"(arg2), "d"(arg3), "r"(_rbx)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall5(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall), "D"(arg1), "S"(arg2), "d"(arg3), "r"(_rbx), "r"(_r8)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall6(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall), "D"(arg1), "S"(arg2), "d"(arg3), "r"(_rbx), "r"(_r8), "r"(_r9)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall7(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    int64_t ret;
    __asm__ volatile(
        "syscall"
        : "=a"(ret)
        : "a"(syscall), "D"(arg1), "S"(arg2), "d"(arg3), "r"(_rbx), "r"(_r8), "r"(_r9), "r"(_r10)
        : "memory", "rcx", "r11"
    );
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall8(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7,
    uint64_t arg8
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    register uint64_t _r12 __asm__("r12") = arg8;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall),
                       "D"(arg1),
                       "S"(arg2),
                       "d"(arg3),
                       "r"(_rbx),
                       "r"(_r8),
                       "r"(_r9),
                       "r"(_r10),
                       "r"(_r12)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall9(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7,
    uint64_t arg8,
    uint64_t arg9
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    register uint64_t _r12 __asm__("r12") = arg8;
    register uint64_t _r13 __asm__("r13") = arg9;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall),
                       "D"(arg1),
                       "S"(arg2),
                       "d"(arg3),
                       "r"(_rbx),
                       "r"(_r8),
                       "r"(_r9),
                       "r"(_r10),
                       "r"(_r12),
                       "r"(_r13)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall10(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7,
    uint64_t arg8,
    uint64_t arg9,
    uint64_t arg10
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    register uint64_t _r12 __asm__("r12") = arg8;
    register uint64_t _r13 __asm__("r13") = arg9;
    register uint64_t _r14 __asm__("r14") = arg10;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall),
                       "D"(arg1),
                       "S"(arg2),
                       "d"(arg3),
                       "r"(_rbx),
                       "r"(_r8),
                       "r"(_r9),
                       "r"(_r10),
                       "r"(_r12),
                       "r"(_r13),
                       "r"(_r14)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall11(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7,
    uint64_t arg8,
    uint64_t arg9,
    uint64_t arg10,
    uint64_t arg11
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    register uint64_t _r12 __asm__("r12") = arg8;
    register uint64_t _r13 __asm__("r13") = arg9;
    register uint64_t _r14 __asm__("r14") = arg10;
    register uint64_t _r15 __asm__("r15") = arg11;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall),
                       "D"(arg1),
                       "S"(arg2),
                       "d"(arg3),
                       "r"(_rbx),
                       "r"(_r8),
                       "r"(_r9),
                       "r"(_r10),
                       "r"(_r12),
                       "r"(_r13),
                       "r"(_r14),
                       "r"(_r15)
                     : "memory", "rcx", "r11");
    return ret;
}

_CASCADE_INLINE int64_t cascade_syscall12(
    cascade_syscall syscall,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t arg4,
    uint64_t arg5,
    uint64_t arg6,
    uint64_t arg7,
    uint64_t arg8,
    uint64_t arg9,
    uint64_t arg10,
    uint64_t arg11,
    uint64_t arg12
) {
    register uint64_t _rbx __asm__("rbx") = arg4;
    register uint64_t _r8 __asm__("r8") = arg5;
    register uint64_t _r9 __asm__("r9") = arg6;
    register uint64_t _r10 __asm__("r10") = arg7;
    register uint64_t _r12 __asm__("r12") = arg8;
    register uint64_t _r13 __asm__("r13") = arg9;
    register uint64_t _r14 __asm__("r14") = arg10;
    register uint64_t _r15 __asm__("r15") = arg11;
    register uint64_t _rbp __asm__("rbp") = arg12;
    int64_t ret;
    __asm__ volatile("syscall"
                     : "=a"(ret)
                     : "a"(syscall),
                       "D"(arg1),
                       "S"(arg2),
                       "d"(arg3),
                       "r"(_rbx),
                       "r"(_r8),
                       "r"(_r9),
                       "r"(_r10),
                       "r"(_r12),
                       "r"(_r13),
                       "r"(_r14),
                       "r"(_r15),
                       "r"(_rbp)
                     : "memory", "rcx", "r11");
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
