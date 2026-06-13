// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_COMMON_H
#define _CASCADE_COMMON_H

#include <stddef.h>
#include <stdint.h>

#define _CASCADE_CONCAT_IMPL(a, b) a##b
#define _CASCADE_CONCAT(a, b) _CASCADE_CONCAT_IMPL(a, b)

#ifdef __COUNTER__
#define _CASCADE_UID __COUNTER__
#else
#define _CASCADE_UID __LINE__
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_TRAP() __builtin_trap()
#elif defined(__x86_64__) || defined(__i386__)
#define _CASCADE_TRAP() __asm__ __volatile__("ud2")
#elif defined(__aarch64__)
#define _CASCADE_TRAP() __asm__ __volatile__("udf #0")
#elif defined(__riscv)
#define _CASCADE_TRAP() __asm__ __volatile__("unimp")
#else
#define _CASCADE_TRAP() (*(volatile int *)0 = 0)
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_UNREACHABLE() unreachable()
#elif defined(__clang__) || defined(__GNUC__)
#define _CASCADE_UNREACHABLE() __builtin_unreachable()
#else
#define _CASCADE_UNREACHABLE() _CASCADE_TRAP()
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_STATIC_ASSERT(expr, msg) static_assert(expr, msg)
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define _CASCADE_STATIC_ASSERT(expr, msg) _Static_assert(expr, msg)
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#define _CASCADE_STATIC_ASSERT(expr, msg) static_assert(expr, msg)
#else
#define _CASCADE_STATIC_ASSERT(expr, msg)                                                          \
    typedef char _CASCADE_CONCAT(_cascade_assert_, _CASCADE_UID)[(expr) ? 1 : -1]
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_LIKELY(x) __builtin_expect(!!(x), 1)
#define _CASCADE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define _CASCADE_LIKELY(x) (x)
#define _CASCADE_UNLIKELY(x) (x)
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define _CASCADE_ALIGNOF(type) _Alignof(type)
#elif defined(__clang__) || defined(__GNUC__)
#define _CASCADE_ALIGNOF(type) __alignof__(type)
#else
#error "_CASCADE_ALIGNOF: no alignof support on this compiler"
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_INLINE static inline __attribute__((always_inline))
#else
#define _CASCADE_INLINE static inline
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L && !defined(__cplusplus)
#define _CASCADE_ARRAY_LEN(n) static n
#else
#define _CASCADE_ARRAY_LEN(n)
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_NONNULL_ARGS(...) __attribute__((nonnull(__VA_ARGS__)))
#define _CASCADE_NONNULL __attribute__((nonnull))
#else
#define _CASCADE_NONNULL_ARGS(...)
#define _CASCADE_NONNULL
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_NORETURN [[noreturn]]
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define _CASCADE_NORETURN _Noreturn
#elif defined(__GNUC__) || defined(__clang__)
#define _CASCADE_NORETURN __attribute__((noreturn))
#else
#define _CASCADE_NORETURN
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_RETURNS_NONNULL __attribute__((returns_nonnull))
#else
#define _CASCADE_RETURNS_NONNULL
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
#define _CASCADE_NODISCARD __attribute__((warn_unused_result))
#else
#define _CASCADE_NODISCARD
#endif

#endif // _CASCADE_COMMON_H
