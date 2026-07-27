# Repository Guidelines

## Project Structure & Module Organization

This is a Zig 2D platformer built with `raylib-zig`. Runtime code lives in `src/`: `main.zig` initializes the window and game loop, `player.zig` owns player behavior, and `root.zig` exposes the reusable module tested by the build. Keep focused helpers in sibling files such as `utils.zig` and `debug.zig`.

Project configuration is in `build.zig` and `build.zig.zon`. The root-level `player.png` is a game asset. Generated directories (`zig-out/`, `zig-pkg/`, and `.zig-cache/`) are ignored; do not edit or commit them.

## Build, Test, and Development Commands

- `zig build` — compile and install `2d_platformer` to `zig-out/bin/`.
- `zig build run` — build and launch the game locally.
- `zig build test` — run tests for both the reusable module and executable root module.
- `zig fmt build.zig build.zig.zon src/*.zig` — format Zig sources before committing.

## Coding Style & Naming Conventions

Use `zig fmt`; it defines indentation and layout. Follow existing Zig conventions: `camelCase` for variables and functions (`updatePlayer`), `PascalCase` for types (`Player`), and lowercase file names such as `player.zig`. Keep raylib calls in the game loop or the owning subsystem, propagate fallible operations with `try`, and avoid unrelated refactors in gameplay changes.

## Testing Guidelines

Add Zig `test "descriptive behavior" { ... }` blocks close to the code they cover. Prefer deterministic tests for movement, boundary checks, and utility logic; avoid opening a window or loading textures in unit tests. Run `zig build test` before submitting changes.

## Agent Instructions

Before changing Zig code or build configuration, read the Zig 0.16 documentation for the APIs and language features involved. Also inspect the relevant Zig standard-library source files in the local Zig installation; use the implementation to resolve behavior, ownership, or API questions rather than guessing. State which documentation and source areas informed non-trivial changes.

## Commit & Pull Request Guidelines

This branch has no prior commits, so use short imperative subjects, for example `Add player boundary test`. Keep each commit focused. Pull requests should explain gameplay or build changes, list validation commands run, link relevant issues, and include a screenshot or short recording for visual changes. Do not rename `platformer.app` unless the change explicitly requires it.
