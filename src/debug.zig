const pl = @import("player.zig");
const rl = @import("raylib");

const std = @import("std");
const Io = std.Io;
const io = Io.Threaded.global_single_threaded.io();

pub var shfps: bool = false;
const dbgKey: rl.KeyboardKey = rl.KeyboardKey.left_alt;

pub fn check(player: *pl.Player) !void {
    if (rl.isKeyDown(dbgKey) & rl.isKeyDown(rl.KeyboardKey.left_control)) {
        rl.drawFPS(0, 0);
    }
    if (rl.isKeyDown(dbgKey) & rl.isKeyDown(rl.KeyboardKey.one)) {
        var allocator = std.heap.page_allocator;

        const pos: []u8 = try std.fmt.allocPrint(allocator, "{d}, {d}", .{ player.pos.x, player.pos.y });
        defer allocator.free(pos);

        const buf: [:0]u8 = try allocator.allocSentinel(u8, pos.len, 0);
        defer allocator.free(buf);
        @memcpy(buf, pos);

        try Io.File.stdout().writeStreamingAll(io, buf);
        rl.drawText(buf, 0, 0, 20, rl.Color.white);
    }
}
