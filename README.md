# The 2048 Game
A console-based implementation of the classic 2048 game in C++.

## Features
Random Tile Spawning: Adds a 2 or 4 tile at a random empty spot on the grid.

Move Validations: Checks if there are valid moves left.

Grid Display: Shows the current state of the grid.

Directional Moves: Supports moves in all four directions (up, down, left, right).

Game Over Detection: Detects when no more valid moves are possible.

## How to Play
Run the Program: Compile and run the C++ code.

Move Tiles: Use the following keys to move the tiles:

w: Move up

s: Move down

a: Move left

d: Move right

Objective: Combine tiles with the same number to reach the 2048 tile.

Exit: Press q to quit the game.

## Code Explanation
randomSpawn(): Spawns a new tile (2 or 4) in a random empty spot on the grid.

canMove(): Checks if there are any valid moves left on the grid.

showGrid(): Displays the current state of the grid in the console.

left(): Moves tiles to the left and combines them if possible.

rotateclockwise(): Rotates the grid 90 degrees clockwise.

up(): Rotates the grid, moves tiles up, and then rotates the grid back.

down(): Rotates the grid, moves tiles down, and then rotates the grid back.

right(): Rotates the grid, moves tiles right, and then rotates the grid back.

main(): Initializes the game, takes user input, and handles the game loop.
