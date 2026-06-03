// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef CASCADE_DEFINE_H
#define CASCADE_DEFINE_H

#if defined(__GNUC__) || defined(__clang__)
    #define CASCADE_INLINE static inline __attribute__((always_inline))
#else
    #define CASCADE_INLINE static inline
#endif

#if defined(__GNUC__) || defined(__clang__)
  #define CASCADE_NORETURN __attribute__((noreturn))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
  #define CASCADE_NORETURN _Noreturn
#else
  #define CASCADE_NORETURN
#endif

#endif // CASCADE_DEFINE_H
