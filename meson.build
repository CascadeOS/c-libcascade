# SPDX-License-Identifier: 0BSD
# SPDX-FileCopyrightText: CascadeOS Contributors

project(
    'libcascade',
    'c',
    version: '0.0.2',
    default_options: [
        'c_std=c99',
        'warning_level=3',
        'werror=true',
        'buildtype=debugoptimized',
    ],
)

install = get_option('install')

c_args = [
    '-ffreestanding',
    '-fno-builtin',
    '-fno-stack-protector',
    '-fno-stack-check',
    '-pedantic',
    '-Wunused-parameter',
    '-Wunused-result',
    '-Wstrict-prototypes',
    '-Wmissing-prototypes',
    '-Wswitch-default',
    '-Wswitch-enum',
    '-Wconversion',
    '-Wdouble-promotion',
    '-Wundef',
    '-Wunused',
    '-Warray-bounds',
]

source_files = files(
    'src/debug.c',
    'src/thread.c',
)

incl = include_directories('include')

libcascade = static_library(
    'cascade',
    source_files,
    include_directories: incl,
    c_args: c_args,
    install: install,
)

if install
    install_headers(
        files(
            'include/cascade/debug.h',
            'include/cascade/syscall.h',
            'include/cascade/thread.h',
        ),
        subdir: 'cascade',
    )
    install_headers(
        files(
            'include/cascade/internal/common.h',
        ),
        subdir: 'cascade/internal',
    )

    pkg = import('pkgconfig')
    pkg.generate(
        libcascade,
        name: 'libcascade',
        description: 'CascadeOS C library',
        version: meson.project_version(),
    )
endif

libcascade_dep = declare_dependency(include_directories: incl, link_with: libcascade)