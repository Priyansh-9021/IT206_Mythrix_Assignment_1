# IT206_Mythrix_Assignment_1
# 🐍 Snake Game (C++)

## Authors

- [PRIYANSH](https://github.com/Priyansh-9021/IT206_Mythrix_Assignment_1.git)
- [NAISARGI]
- [NIRAJ]
- [VYOM](https://github.com/Cipher626/SnakeGame_SEM-2-Assignment-1-)

## 📜 Table of Contents
- Project Description
- Key Features
- Installation
- Gameplay Controls
- How To Play
- Data Structure Analysis
- Important Data Structures
- Key Member Functions
- Difficulty Levels
- Code Structure
- License
- Prerequisites
- Contact
- Contributing

## ✨ Project Description

A classic **Snake Game** implemented in C++ using Object-Oriented Programming (OOP) principles. Control a snake to collect food ('F') while avoiding collisions with walls and your own tail. Features customizable snake design, difficulty levels, and a persistent high score system. Built for Windows with minimal dependencies.

## 🌟 Key Features

1. **Customizable Snake Design**: Choose unique characters for the snake's head and body.
2. **Dynamic Difficulty**: Three speed levels (Easy/Medium/Hard) for varied challenges.
3. **Score & High Score**: Track your score and compete for the all-time high score.
4. **Collision Detection**: Game ends if the snake hits walls or its own body.
5. **Windows-Compatible**: Uses `conio.h` for real-time keyboard input.
6. **Random Food Spawning**: Food appears at non-overlapping random positions.
7. **Static High Score**: Persists across game sessions using static class variables.

## 🛠️ Installation 

1. **Clone the Repository**
   git clone https://github.com/Priyansh-9021/IT206_Mythrix_Assignment_1.git 
   cd snake-game-cpp
2. **Compile (Windows)**:
   g++ snake_game.cpp -o snake_game.exe
3. **Run**:
   snake_game.exe

## 🎮 Gameplay Controls

- `W` ➡️ Move Up  
- `A` ➡️ Move Left  
- `S` ➡️ Move Down  
- `D` ➡️ Move Right  
- `X` ➡️ Exit Game  
- `P` ➡️ Restart After Game Over

## 🎮 How To Play

1. **Customize Your Snake**: Enter head/body characters when prompted.
2. **Select Difficulty**:
   - `a` Easy (Slow)
   - `b` Medium 
   - `c` Hard (Fast)
3. **Collect Food**: Grow longer by eating 'F'.
4. **Avoid Collisions**: Walls and self-collisions end the game.
5. **Restart**: Press `P` after game over to play again.

## 📚 Data Structure Analysis

### Core Structures
- **Arrays**: `tailX[100]` and `tailY[100]` store snake body coordinates (max length = 100).
- **Enum**: `Direction` (UP, DOWN, LEFT, RIGHT, STOP) manages movement states.
- **Static Variable**: `highscore` persists across game instances.

### Why Arrays?
- **Fixed Size**: Simplifies memory management but limits snake length.
- **Efficiency**: Direct index access for O(1) tail updates.

## 🏗️ Code Structure

### `SnakeGame` Class
| Member Variable            | Description                          |
|----------------------------|--------------------------------------|
| `tailX[100]`, `tailY[100]` | Snake body coordinates               |
| `foodX`, `foodY`           | Current food position                |
| `snakehead`, `snakebody`   | Custom head/body characters          |
| `highscore`                | All-time high score (static)         |

### Key Methods
| Method                | Functionality                          |
|-----------------------|----------------------------------------|
| `resetGame()`         | Resets game state                      |
| `Design_Snake()`      | Sets custom head/body characters       |
| `spawnFood()`         | Generates new food position            |
| `draw()`              | Renders game board in console          |
| `logic()`             | Handles movement, collisions, scoring  |
| `updateHighScore()`   | Updates static high score              |

## 🔥 Difficulty Levels

| Level   | Command | Delay (ms) | Description          |
|---------|---------|------------|----------------------|
| Easy    | `a`     | 200 ms     | Slow-paced, relaxed  |
| Medium  | `b`     | 50 ms      | Balanced challenge   |
| Hard    | `c`     | 10 ms      | Lightning-fast       |

## 📜 License
MIT License - Free for educational and personal use. Attribution appreciated!

## 🧰 Prerequisites
- Windows OS (for `conio.h`)
- C++ Compiler (e.g., `g++`)

## 📞 Contact
- 📧 Email: 202401213@daiict.ac.in
- 💻 GitHub: https://github.com/Priyansh-9021/IT206_Mythrix_Assignment_1.git

## 📢 Contributing
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request.  
*All contributions welcome!*
