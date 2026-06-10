// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{ .preferred_optimize_mode = .ReleaseSafe });
    const freestanding_target = blk: {
        var target = b.standardTargetOptions(.{});
        target.query.os_tag = .freestanding;
        target.result.os.tag = .freestanding;
        break :blk target;
    };

    const include_directory = b.path("include");

    const libcascade_module = b.createModule(.{
        .root_source_file = null,
        .target = freestanding_target,
        .optimize = optimize,
        .link_libc = false,
        .link_libcpp = false,
        .sanitize_c = .off,
        .strip = false,
        .no_builtin = true,
        .stack_protector = false,
        .stack_check = false,
        .pic = true,
    });
    libcascade_module.addIncludePath(include_directory);
    libcascade_module.addCSourceFiles(.{
        .files = &.{
            "src/thread.c",
        },
        .flags = &.{
            "-ffreestanding",
            "-fno-builtin",
            "-fno-stack-protector",
            "-fno-stack-check",
            "-pedantic",
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-Wunused-parameter",
            "-Wunused-result",
            "-Wstrict-prototypes",
            "-Wmissing-prototypes",
            "-Wswitch-default",
            "-Wswitch-enum",
            "-Wconversion",
            "-Wdouble-promotion",
            "-Wundef",
            "-Wunused",
            "-Warray-bounds",
            "-Werror",
            "-std=c99",
        },
    });

    const c_libcascade = b.addLibrary(.{
        .name = "cascade",
        .linkage = .static,
        .root_module = libcascade_module,
    });
    c_libcascade.installHeadersDirectory(include_directory, "", .{});
    b.installArtifact(c_libcascade);
}
