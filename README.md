# 🎲 Tic-Tac-Toe SFML

A simple Tic-Tac-Toe game implemented in C++ using the SFML library. This project demonstrates handling window events, drawing shapes and text, game logic, and basic UI elements like buttons and keyboard controls.

<p align="center">
    <img width="559" height="633" alt="image" src="https://github.com/user-attachments/assets/d4c69e17-a2ab-433a-9350-fdc9bf976136" />
</p>

---

## 🕹️ Features

- Classic 3x3 Tic-Tac-Toe game
- Clickable grid to place X or O marks
- Keyboard support: press **R** to restart, **Escape** to exit
- Restart button on screen
- Highlights winning line with a thicker green line
- Displays winner or tie message
- Clean and readable retro-style UI
- Works with a workaround for OpenGL compatibility issues on some systems

---

## 🖥️ How to Build

### Install SFML on Linux (Ubuntu/Debian):

```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

### Compile and execute:

```bash
make
./ticTacToe
```

---

## 🔧 Troubleshooting
OpenGL and Graphics Issues
If you encounter errors such as:

```bash
Setting vertical sync not supported
Segmentation fault (core dumped)
```
or the game crashes at startup, your graphics driver might be incompatible with SFML’s default hardware rendering.

To fix this, run the game with software rendering enabled:

```bash
export LIBGL_ALWAYS_SOFTWARE=1
./ticTacToe
```
This forces the use of software rendering and can resolve compatibility issues on certain machines.

---

## 📁 Assets
Fonts are loaded from the assets/ folder. Make sure the font files (e.g. ShareTechMono-Regular.ttf) are available in that directory.

---

## ⏳ Future Improvements

- Add score tracking
- Improve UI with animations and sounds
- Support for different board sizes

---

## ⚖️ License
This project is open for personal, educational, or non-commercial use. Feel free to modify and share it.

