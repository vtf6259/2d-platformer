const rl = @import("raylib");
const debug = @import("debug.zig");
const std = @import("std");

pub const Player = struct { texture: rl.Texture, pos: rl.Vector2, size: rl.Vector2, boundry: rl.Vector2 };

pub fn updatePlayer(player: *Player) !void {
    rl.drawTextureV(player.texture, player.pos, rl.Color.white);
    try debug.check(player); // debug stuff
    var buf: [32]u8 = undefined;
    const huh: []u8 = try std.fmt.bufPrint(&buf, "                  \r{d}", .{player.pos.x});
    try std.Io.File.stdout().writeStreamingAll(std.Io.Threaded.global_single_threaded.io(), huh);
}
