# so_long

<img width="767" alt="Capture d’écran 2022-12-23 à 22 45 14" src="https://user-images.githubusercontent.com/96823772/209408094-e2535116-bd86-4623-82d7-a151a47a0a43.png">


<img width="1212" alt="Screen Shot 2022-12-20 at 5 55 14 PM" src="https://user-images.githubusercontent.com/96823772/208722821-a2b03faf-9151-4d03-881d-e9dc53736e3c.png">
This is a small game project from 1337/42school implemented using MiniLibX. The project is inspired by Game Freak's Pokemon Firered.

## Goals
This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

## Getting Started
```
🚨 Please check that you have mlxlib installed in your machine.
```
### Install
```bash
$ make
```

### Usage
```bash
$ ./so_long [MAP_FILE.ber]
```
Only map files with extension `.ber` are available. Map file examples are available in the `maps/` directory.

```bash
$ ./so_long maps/map.ber
```
Run the code to use all the features of the game.

### HOW TO PLAY
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.

|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`ESC ⎋`|Close the game window|

## Reference
 * [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
 * [42Docs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
 * [taelee42/mlx_example](https://github.com/taelee42/mlx_example)
 * [pret/Disassembly of Pokémon FireRed and LeafGreen](https://github.com/pret/pokefirered)
