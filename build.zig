// SPDX-License-Identifier: 0BSD
// SPDX-FileCopyrightText: CascadeOS Contributors

const std = @import("std");

pub fn build(b: *std.Build) void {
    const c_libcascade = b.addLibrary(.{
        .name = "c-libcascade",
        .linkage = .static,
        .root_module = b.createModule(.{
            .root_source_file = null,
            .target = b.standardTargetOptions(.{}),
            .optimize = .ReleaseSmall,
            .sanitize_c = .off,
            .strip = true,
            .no_builtin = true,
        }),
    });
    c_libcascade.installHeadersDirectory(b.path("include"), "", .{});

    // TODO: needing an empty C file to create a header-only library is annoying
    // TODO: in addition a empty library file is actually produced and passed to the dependants linker :(
    c_libcascade.root_module.addCSourceFile(.{ .file = b.addWriteFiles().add("empty.c", "") });

    b.installArtifact(c_libcascade);
}
