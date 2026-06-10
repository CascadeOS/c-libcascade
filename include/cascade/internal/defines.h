// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_DEFINE_H
#define _CASCADE_DEFINE_H

#include <stddef.h>

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_INLINE static inline __attribute__((always_inline))
#else
#define _CASCADE_INLINE static inline
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_LIKELY(x) __builtin_expect(!!(x), 1)
#define _CASCADE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define _CASCADE_LIKELY(x) (x)
#define _CASCADE_UNLIKELY(x) (x)
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_NORETURN [[noreturn]]
#elif defined(__GNUC__) || defined(__clang__)
#define _CASCADE_NORETURN __attribute__((noreturn))
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define _CASCADE_NORETURN _Noreturn
#else
#define _CASCADE_NORETURN
#endif

#if defined(__GNUC__) || defined(__clang__)
#define _CASCADE_TRAP() __builtin_trap()
#else
#define _CASCADE_TRAP() (*(volatile int *)0 = 0)
#endif

#if defined(__clang__) || defined(__GNUC__)
#define _CASCADE_UNREACHABLE() __builtin_unreachable()
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define _CASCADE_UNREACHABLE() unreachable()
#else
#define _CASCADE_UNREACHABLE() _CASCADE_TRAP()
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define _CASCADE_ALIGNOF(type) _Alignof(type)
#elif defined(__clang__) || defined(__GNUC__)
#define _CASCADE_ALIGNOF(type) __alignof__(type)
#else
#error "_CASCADE_ALIGNOF: no alignof support on this compiler"
#endif

#define _CASCADE_CONCAT_IMPL(a, b) a##b
#define _CASCADE_CONCAT(a, b) _CASCADE_CONCAT_IMPL(a, b)

#ifdef __COUNTER__
#define _CASCADE_UID __COUNTER__
#else
#define _CASCADE_UID __LINE__
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

#endif // _CASCADE_DEFINE_H
