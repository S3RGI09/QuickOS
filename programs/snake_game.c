#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int gameOver;
int score;
int foodX, foodY;
int snakeX[100], snakeY[100];
int length;
int dir;
int speed;

void Setup() {
    gameOver = 0;
    dir = RIGHT;
    score = 0;
    length = 1;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    srand(time(NULL));
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == snakeY[0] && j == snakeX[0])
                printf("O");
            else if (i == foodY && j == foodX)
                printf("*");
            else {
                int printSnake = 0;
                for (int k = 1; k < length; k++) {
                    if (i == snakeY[k] && j == snakeX[k]) {
                        printf("o");
                        printSnake = 1;
                    }
                }
                if (!printSnake)
                    printf(" ");
            }
            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void Logic() {
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = snakeX[0] + ((dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0);
    snakeY[0] = snakeY[0] + ((dir == DOWN) ? 1 : (dir == UP) ? -1 : 0);
    for (int i = 1; i < length; i++) {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        score += 10;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
        length++;
    }
    if (snakeX[0] >= WIDTH || snakeX[0] < 0 || snakeY[0] >= HEIGHT || snakeY[0] < 0)
        gameOver = 1;
    for (int i = 1; i < length; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
            gameOver = 1;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}