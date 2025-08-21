Snake King – Console Snake Game

A simple console-based Snake Game written in C++ for Windows.
Move your snake to collect fruits, grow your tail, and score points. Avoid hitting yourself or quit anytime.

Features

Playable in the console

Smooth movement with W, A, S, D

Screen wraps around when hitting walls

Growing tail when eating fruit

Score tracking

Exit anytime by pressing X

Requirements

Operating System: Windows (required for <conio.h> and <windows.h>)

Compiler: g++ (MinGW, TDM-GCC, or MSVC)

How to Compile & Run
1. Save the Code

Save the source code as:

snake.cpp

2. Open Command Prompt or PowerShell

Navigate to the folder containing snake.cpp.

3. Compile

Use:

g++ snake.cpp -o snake


If using MSVC, compile with:

cl snake.cpp

4. Run

After compilation, run:

snake

How to Play
Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
X	Exit Game

Goal: Eat the * fruit to grow your tail and increase your score by 10 points each time.

Customization

You can tweak the game easily:

Change snake speed:
Edit Sleep(100); in main() to a smaller number for faster movement.

Change grid size:
Update:

const int height = 20;
const int width = 20;


Change snake start direction:
In setup():

dir = RIGHT;

Known Issues

Works only in Windows (due to conio.h and Sleep).

Snake doesn’t move until you press a direction key unless you set a default direction in setup().
