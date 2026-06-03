// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef CASCADE_THREAD_H
#define CASCADE_THREAD_H

#include <cascade/defines.h>

#ifdef __cplusplus
extern "C" {
#endif

CASCADE_NORETURN void cascade_exit_current_thread(void);

#ifdef __cplusplus
}
#endif

#endif // CASCADE_THREAD_H
