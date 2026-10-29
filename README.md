# cub3D

A Wolfenstein 3D-style raycasting engine in C, built at École 42 (Brussels).

Renders a first-person 3D view from a 2D map with textured walls, using the MiniLibX graphics library.

## Features

- Raycasting (DDA) with per-direction wall textures
- Floor and ceiling colors from the scene file
- Player movement and rotation (W/A/S/D, arrow keys), ESC to quit
- `.cub` scene parser with map validation (closed walls, single spawn point)

## Build and run

macOS (MiniLibX OpenGL is bundled):

```bash
make
./cub3D maps/map_enonce.cub
```
