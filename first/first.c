#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "first.h"

#define SIZE 4

int score;

int board[SIZE][SIZE] = {
    0
};

int vievboard[SIZE][SIZE] = {
    0
};


void print_board(int vievboard[SIZE][SIZE], int *score) { printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", vievboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%4d", *score);
    printf("\n");
}


void generete_new_numb(int board[SIZE][SIZE]) //генерация числа в случайном месте
{
    time_t t1;
    srand ((unsigned) time (&t1));
    int i, j;
    int empty_tiles[SIZE * SIZE][2];
    int num_empty_tiles = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty_tiles[num_empty_tiles][0] = i;
                empty_tiles[num_empty_tiles][1] = j;
                num_empty_tiles++;
            }
        }
    }

    if (num_empty_tiles > 0) {
        int random_index = rand() % num_empty_tiles;
        int x = empty_tiles[random_index][0];
        int y = empty_tiles[random_index][1];
        int value = (rand() % 2 + 1) * 2;  // generates either 2 or 4
        board[x][y] = value;
    }
}

void getfield(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            vievboard[i][j] = board[i][j];
        }
    }
}


void shift_left(int board[SIZE][SIZE], int *score) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            for (k = j + 1; k < SIZE; k++) {
                if (board[i][k] == 0) {
                    continue;
                }
                if (board[i][j] == board[i][k]) {
                    board[i][j] *= 2;
                    *score += board[i][j];
                    board[i][k] = 0;
                }
                break;
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                for (k = j + 1; k < SIZE; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void shift_right(int board[SIZE][SIZE], int *score) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == 0) {
                continue;
            }
            for (k = j - 1; k >= 0; k--) {
                if (board[i][k] == 0) {
                    continue;
                }
                if (board[i][j] == board[i][k]) {
                    board[i][j] *= 2;
                    *score += board[i][j];
                    board[i][k] = 0;
                }
                break;
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == 0) {
                for (k = j - 1; k >= 0; k--) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void shift_up(int board[SIZE][SIZE], int *score) {
    int i, j, k;
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE - 1; i++) {
            if (board[i][j] == 0) {
                continue;
            }
            for (k = i + 1; k < SIZE; k++) {
                if (board[k][j] == 0) {
                    continue;
                }
                if (board[i][j] == board[k][j]) {
                    board[i][j] *= 2;
                    *score += board[i][j];
                    board[k][j] = 0;
                }
                break;
            }
        }
    }

    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE - 1; i++) {
            if (board[i][j] == 0) {
                for (k = i + 1; k < SIZE; k++) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void shift_down(int board[SIZE][SIZE], int *score) {
    int i, j, k;
    for (j = 0; j < SIZE; j++) {
        for (i = SIZE - 1; i > 0; i--) {
            if (board[i][j] == 0) {
                continue;
            }
            for (k = i - 1; k >= 0; k--) {
                if (board[k][j] == 0) {
                    continue;
                }
                if (board[i][j] == board[k][j]) {
                    board[i][j] *= 2;
                    *score += board[i][j];
                    board[k][j] = 0;
                }
                break;
            }
        }
    }

    for (j = 0; j < SIZE; j++) {
        for (i = SIZE - 1; i > 0; i--) {
            if (board[i][j] == 0) {
                for (k = i - 1; k >= 0; k--) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int game_over(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
            if (j < SIZE - 1 && board[i][j] == board[i][j + 1]) {
                return 0;
            }
            if (i < SIZE - 1 && board[i][j] == board[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}



//gcc -c file.c

//ar rcs namebibl bsdkf.o dsad.o

// gcc -o main main.c -L. -lmylibb