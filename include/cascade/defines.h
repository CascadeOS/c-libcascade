// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef CASCADE_DEFINE_H
#define CASCADE_DEFINE_H

#include <stddef.h>

#if defined(__GNUC__) || defined(__clang__)
    #define CASCADE_INLINE static inline __attribute__((always_inline))
#else
    #define CASCADE_INLINE static inline
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define CASCADE_LIKELY(x)   __builtin_expect(!!(x), 1)
    #define CASCADE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
    #define CASCADE_LIKELY(x)   (x)
    #define CASCADE_UNLIKELY(x) (x)
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
    #define CASCADE_NORETURN [[noreturn]]
#elif defined(__GNUC__) || defined(__clang__)
    #define CASCADE_NORETURN __attribute__((noreturn))
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
    #define CASCADE_NORETURN _Noreturn
#else
    #define CASCADE_NORETURN
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define CASCADE_TRAP() __builtin_trap()
#else
    #define CASCADE_TRAP() (*(volatile int*)0 = 0)
#endif

#if defined(__clang__) || defined(__GNUC__)
    #define CASCADE_UNREACHABLE() __builtin_unreachable()
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
    #define CASCADE_UNREACHABLE() unreachable()
#else
    #define CASCADE_UNREACHABLE() CASCADE_TRAP()
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
    #define CASCADE_ALIGNOF(type) _Alignof(type)
#elif defined(__clang__) || defined(__GNUC__)
    #define CASCADE_ALIGNOF(type) __alignof__(type)
#else
    #error "CASCADE_ALIGNOF: no alignof support on this compiler"
#endif

#endif // CASCADE_DEFINE_H
