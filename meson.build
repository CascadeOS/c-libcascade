# SPDX-License-Identifier: 0BSD
# SPDX-FileCopyrightText: CascadeOS Contributors

project('libcascade', version: '0.0.1')

incl = include_directories('include')

install_headers(
  'include/cascade/syscall.h',
  subdir: 'cascade'
)

pkg = import('pkgconfig')
pkg.generate(
  name: 'cascade',
  description: 'CascadeOS C library',
)

libcascade_dep = declare_dependency(include_directories: incl)
