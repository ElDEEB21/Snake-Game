# Classic Snake Game

This repository contains a simple implementation of the classic Snake game written in C++. The game utilizes basic console input and output, providing a fun and interactive experience for players directly from their terminal window.

## Game Features

- **Classic Gameplay:** Navigate the snake around the screen, eating fruits to grow longer while avoiding collisions with the walls or the snake's own tail.
- **Score Tracking:** Each fruit eaten increases the player's score and makes the snake longer.
- **Game Controls:** Use the keyboard arrows (WASD or w, a, s, d) to change the direction of the snake.
- **Pause and Exit:** Players can pause the game by pressing `P` or `p` and exit the game by pressing `X` or `x`.

## Installation

To run the Snake game, you will need a C++ compiler that supports C++11 (or later) and the Windows.h library for console manipulation. This game is designed to be run on Windows platforms.

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/ElDEEB21/Snake-Game.git
    ```
2. Compile the code using a C++ compiler:
    ```bash
    g++ -o SnakeGame main.cpp
    ```
3. Run the executable:
    ```bash
    ./SnakeGame
    ```

## How to Play

1. Run the executable file.
2. Use the following keys to control the snake:
   - `W` or `w`: Move up
   - `S` or `s`: Move down
   - `A` or `a`: Move left
   - `D` or `d`: Move right
3. Avoid hitting the walls or the snake's own tail.
4. Eat fruits to increase your score.
5. To pause the game, press `P` or `p`.
6. To exit the game, press `X` or `x`.

If you lose the game, you will be given an option to restart by pressing `Y` or `y`, or you can choose to exit by pressing any other key.

## Code Structure

The game is structured around several key functions:

- `Intro()`: Displays the game's welcome screen.
- `sheft_right()`: Handles the movement of the snake's tail.
- `generate_fruit()`: Randomly places a fruit within the game boundaries.
- `Setup()`: Initializes the game settings.
- `draw()`: Renders the game state to the console.
- `input()`: Captures and processes keyboard input.
- `move()`: Updates the game state, including the movement of the snake and collision detection.

## Contribution

Contributions to this project are welcome. You can help by:

- Reporting bugs
- Suggesting new features
- Improving the codebase and documentation

Please feel free to fork the repository and submit pull requests.

---

Enjoy the game and feel free to provide feedback or contribute to its development!
