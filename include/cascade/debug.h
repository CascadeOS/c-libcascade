// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

#ifndef _CASCADE_DEBUG_H
#define _CASCADE_DEBUG_H

#include <cascade/internal/defines.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Output a debug message.
 *
 * This is not intended to be used by normal userspace programs and instead is intended for logs
 * from system libraries like libc.
 *
 * The message is assumed to be UTF-8 encoded.
 *
 * If the message does not end with a newline, one will be appended.
 *
 * No guarantees are made about the destination of the message, the implementation may choose to
 * discard it or send it to any number of destinations.
 *
 * Any errors encountered while writing the message are ignored and may cause the message to be
 * truncated.
 *
 * @param len length of the message
 * @param buf pointer to the message
 */
void cascade_debug_print(uint64_t len, const uint8_t buf[static len]);

#ifdef __cplusplus
}
#endif

#endif // _CASCADE_DEBUG_H
