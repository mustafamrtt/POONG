
![image](https://github.com/user-attachments/assets/fc50217f-bede-41cc-9dd9-d7b21de5831f)
![image](https://github.com/user-attachments/assets/36db3e4b-0bb7-4831-843b-346d994a9002)
#  POONG

POONG is a simple two-player Pong clone developed in C using the raylib graphics library. It provides a minimal yet fun retro-style arcade experience.

---

## Features

-  Local 2-player mode
- Basic score tracking
-  Built with `raylib` for graphical rendering
- Restartable matches with continuous play

---

##  Requirements

- A C compiler (e.g., GCC or Clang)
- [`raylib`](https://www.raylib.com/) library installed (v4.0+ recommended)

---

##  How to Run

###  Linux / macOS

1. Install `raylib` (example for Debian-based systems):

```bash

sudo apt install libraylib-dev

```
2.Clone the repoaitory:

```bash

git clone https://github.com/mustafamrtt/POONG.git
cd POONG
```
3.Compile and run

```bash

gcc main.c -o poong -lraylib -lm -ldl -lpthread -lGL
./poong

```
Windows (MSYS2 Recommended)

1.Install MSYS2 and open the MSYS terminal.
2.Install necessary packages.
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib
```
3.Compile the game:
```bash
gcc main.c -o poong -lraylib -lopengl32 -lgdi32 -lwinmm
```