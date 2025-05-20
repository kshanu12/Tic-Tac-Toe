
# Tic Tac Toe Game in C

A console-based Tic Tac Toe game implemented in C language with support for both multiplayer and singleplayer (vs computer) modes.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Files](#files)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [Gameplay Instructions](#gameplay-instructions)
- [Code Structure](#code-structure)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

## Overview

This project implements a classic Tic Tac Toe game playable on the console. Users can choose between two players or play against the computer. The program keeps track of the score and supports replaying multiple rounds.

---

## Features

- Multiplayer mode: Two human players can compete.
- Singleplayer mode: Play against a computer with basic AI.
- Clear console-based UI with board display.
- Move history tracking using linked lists.
- Input validation to ensure moves are valid and cells are empty.
- Win detection for rows, columns, and diagonals.
- Score tracking across multiple games.
- Replay option after each game.

---

## Files

| File          | Description                                |
|---------------|--------------------------------------------|
| `main.c`      | Entry point of the program, game loop, and main logic. |
| `node.h`      | Definition of the linked list node structure. |
| `display.c`   | Functions to display the board and move history. |
| `display.h`   | Declarations for display functions.         |
| `pages.c`     | User interface pages: welcome, instructions, player setup. |
| `pages.h`     | Declarations for pages functions.            |
| `checks.c`    | Functions for input validation and win detection logic. |
| `checks.h`    | Declarations for check functions.            |

---

## How to Compile

Make sure you have `gcc` installed.

Compile all source files together using:

```bash
gcc main.c display.c pages.c checks.c -o tic_tac_toe
```

This will create an executable file named `tic_tac_toe`.

---

## How to Run

Run the program in the terminal or command prompt:

- On Linux/macOS:

```bash
./tic_tac_toe
```

- On Windows:

```bash
tic_tac_toe.exe
```

---

## Gameplay Instructions

- Choose between Multiplayer (1) or Singleplayer (2).
- Read the instructions displayed on the screen.
- Enter player names (or play against computer if singleplayer).
- Make moves by entering a number from 1 to 9 corresponding to the board positions:

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

- The game alternates turns between players until one wins or the board is full.
- After a game ends, the program asks if you want to play again.
- Scores are tracked and displayed after each game.

---

## Code Structure

- **Linked List for Moves:** Each move is stored as a node containing the board state and move number. This helps display move history.
- **Modular Design:** The program is divided into multiple files for better maintainability:
  - UI pages and input handled in `pages.c`.
  - Board display in `display.c`.
  - Game logic checks in `checks.c`.
  - Main loop in `main.c`.
- **Game Logic:** Functions check rows, columns, and diagonals to detect a winner.

---