#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

bool gameOver;
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tail_len;

void setup();
void draw();
void input();
void logic();

int main() {
    char start;
    cout << "\t-------------------------------" << endl;
    cout << "\t\t :Snake King:" << endl;
    cout << "\t-------------------------------" << endl;
    cout << "\tPress 's' to start: ";
    cin >> start;

    if (start == 's') {
        setup();
        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(100); // Adjust speed here for faster/slower snake
        }
    } else {
        cout << "Invalid input. Exiting game." << endl;
    }

    return 0;
}

void setup() {
    srand(time(0)); // Random seed for fruit
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tail_len = 0;
}

void draw() {
    system("cls");

    // Upper border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#"; // Left border

            if (i == headY && j == headX)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "*"; // Fruit
            else {
                bool printTail = false;
                for (int k = 0; k < tail_len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Snake tail
                        printTail = true;
                        break;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#"; // Right border
        }
        cout << endl;
    }

    // Lower border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Display score
    cout << "Score: " << score << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true; // Exit game
            break;
        }
    }
}

void logic() {
    // Move tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < tail_len; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch (dir) {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    }

    // Wall collision (wrap-around)
    if (headX >= width) headX = 0;
    else if (headX < 0) headX = width - 1;

    if (headY >= height) headY = 0;
    else if (headY < 0) headY = height - 1;

    // Check if snake bites itself
    for (int i = 0; i < tail_len; i++) {
        if (tailX[i] == headX && tailY[i] == headY) {
            gameOver = true;
            return;
        }
    }

    // Check if fruit is eaten
    if (headX == fruitX && headY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail_len++;
    }
}

