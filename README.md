# Tic Tac Toe

![Tic Tac Toe Banner](https://upload.wikimedia.org/wikipedia/commons/3/32/Tic_tac_toe.svg)

A simple console-based Tic Tac Toe game written in C.

## How to Play

### 1. Start the Game
- Run the program. You will see a menu with options:
  - 1. 1v1 (Player vs Player)
  - 2. vs BOT (Coming soon)
  - 3. Other games (Coming soon)
  - 4. Patreon
  - 5. Exit

### 2. 1v1 Mode
- Choose option `1` for a two-player game.
- Enter the names for Player 1 and Player 2.
- Player 1 will play as `X`, Player 2 as `O`.
- Enter the number of rounds you want to play.

### 3. Game Board
- The board positions are numbered as follows:

  ```
   1 | 2 | 3
  ---|---|---
   4 | 5 | 6
  ---|---|---
   7 | 8 | 9
  ```

- On your turn, enter the number corresponding to the position where you want to place your mark (`X` or `O`).

### 4. Winning the Game
- The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the round.
- If all positions are filled and no player has won, the round is a draw.

### 5. End of Game
- After all rounds are played, the game thanks you for playing and returns to the menu.

## Requirements

- C compiler (e.g., GCC)
- Windows or Linux terminal

## How to Compile and Run

Open a terminal in the project directory and run:

```sh
gcc tictactoe.c -o tictactoe
./tictactoe
```

## Notes

- Only the 1v1 mode is currently implemented.
- BOT and other games will be added soon.

Enjoy playing!
