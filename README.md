*This project has been created as part of the 42 curriculum by .*

# cub3D

## Description

`cub3D` is a mandatory-style raycasting project built with `minilibx-linux`.
This repository currently includes the rendering loop, MLX integration, textured
wall drawing, floor and ceiling colors, player movement, rotation, collision
checks, cleanup, and scene validation on an in-memory map.

The parser module is intentionally isolated behind `parse_file()` so it can be
replaced cleanly. The current stub only checks the `.cub` path and injects the
demo scene used to exercise the rest of the engine.

## Instructions

Build:

```bash
make
```

Run:

```bash
./cub3D maps/demo.cub
```

Controls:

- `W`, `A`, `S`, `D`: move
- `Left`, `Right`: rotate
- `ESC`: quit

## Resources

- `cub3d.pdf`
- `pdf/Raycasting1.pdf`
- `pdf/Raycasting2.pdf`
- `pdf/Raycasting3.pdf`
- `minilibx-linux/README.md`

AI was used to speed up the repetitive scaffolding work for the non-parser
mandatory modules, then the generated code was reviewed and adjusted inside the
repository.
