const rl = @import("raylib");
const pl = @import("player.zig");
const std = @import("std");
const Io = std.Io;
const io = Io.Threaded.global_single_threaded.io();

pub fn main() !void {
    rl.initWindow(800, 600, "title: [:0]const u8");
    rl.setTargetFPS(120);
    defer rl.closeWindow();
    const asset: rl.Texture = try rl.loadTexture("player.png");
    var player: pl.Player = pl.Player{ .texture = asset, .pos = rl.Vector2{ .x = 0, .y = 0 }, .size = rl.Vector2{ .x = 50, .y = 50 }, .boundry = rl.Vector2{ .x = -1, .y = -1 } };
    while (!rl.windowShouldClose()) {
        rl.clearBackground(rl.Color.black);
        rl.beginDrawing();
        try pl.updatePlayer(&player);
        rl.endDrawing();
    }
}
