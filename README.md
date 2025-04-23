# 2048 Game (Command Line)

This is a command-line version of the popular 2048 puzzle game, implemented in C++. It features a 4x4 grid where you merge tiles with the same number to reach the 2048 tile and win.

## Features

* **Standard 4x4 Grid:** Play on the classic 4x4 game board.
* **Tile Merging:** Combine identical adjacent tiles by sliding them.
* **Random Tile Spawning:** New 2 or 4 tiles appear randomly on empty squares after each valid move.
* **Directional Movement:** Use 'w', 'a', 's', 'd' keys to slide tiles up, left, down, or right.
* **Win Condition:** Reach the 2048 tile to win the game.
* **Game Over Detection:** The game ends when no more moves are possible.

## Getting Started

### Prerequisites

To compile and run this game, you will need:

* A C++ compiler (like g++).
* A terminal or command prompt.

### Compiling and Running

1.  Save the provided C++ code as a `.cpp` file (e.g., `2048_game.cpp`).
2.  Open a terminal or command prompt.
3.  Navigate to the directory where you saved the file.
4.  Compile the program using your C++ compiler. For example, with g++:

    ```bash
    g++ 2048_game.cpp -o 2048_game
    ```

5.  Run the compiled program:

    ```bash
    ./2048_game
    ```

## How to Play

1.  When the game starts, you will see a 4x4 grid with a couple of initial tiles (either 2 or 4).
2.  Use the following keys to make your moves:
    * `w`: Slide tiles **up**
    * `a`: Slide tiles **left**
    * `s`: Slide tiles **down**
    * `d`: Slide tiles **right**
    * `q`: **Quit** the game
3.  When you slide tiles, any tiles with the same number that collide will merge into a single tile with the sum of their values (e.g., 2 and 2 merge into 4, 4 and 4 merge into 8, and so on).
4.  After each valid move, a new tile (2 or 4) will appear in a random empty spot on the grid.
5.  Keep merging tiles to create higher numbers.
6.  The game continues until you create the 2048 tile (you win!) or until there are no more possible moves (the grid is full and no adjacent tiles can be merged - Game Over).

## How it Works (Behind the Scenes)

* The game board is represented by a 2D integer array `grid[4][4]`.
* `randomSpawn()` adds a new 2 or 4 tile to a random empty cell on the grid.
* `showGrid()` displays the current state of the game board in the console.
* `left()` is the core function for sliding and merging tiles to the left. The `right()`, `up()`, and `down()` functions utilize a `rotateclockwise()` helper function to rotate the grid, apply the `left()` logic, and then rotate it back to simulate moves in other directions.
* `rotateclockwise()` rotates the entire grid 90 degrees clockwise.
* `canMove()` checks if there are any empty cells or adjacent tiles with the same value, indicating if a move is possible.
* `check2048()` checks if the winning tile (2048) is present on the board.
* The `main()` function initializes the game, handles user input for moves, calls the appropriate movement functions, spawns new tiles, checks for win/game over conditions, and manages the game loop.
