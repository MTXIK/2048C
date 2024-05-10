#include <stdio.h>
#include "first.h"
#include "first.c"

#define SIZE 4

char TEST_IS_GAME_OVER_NOT_PASSED[] = "test is_game_over not passed";
char TEST_SHIFT_DOWN_NOT_PASSED[] = "test shift_down not passed";
char TEST_SHIFT_UP_NOT_PASSED[] = "test shift_up not passed";
char TEST_SHIFT_LEFT_NOT_PASSED[] = "test shift_left not passed";
char TEST_SHIFT_RIGHT_NOT_PASSED[] = "test shift_right not passed";
char TEST_GENRATE_NEW_NUMB_NOT_PASSED[] = "test generate_new_numb not passed";

int rboard[SIZE][SIZE] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

int test_shift_down(char** message) {
    int score = 0;
    int rtboard[SIZE][SIZE] = {
            {2, 0, 4, 0},
            {4, 0, 0, 4},
            {0, 0, 0, 2},
            {0, 0, 4, 4}
    };

    shift_down(rtboard, &score);

    int expected_rtboard[SIZE][SIZE] = {
            {0, 0, 0, 0},
            {0, 0, 0, 4},
            {2, 0, 0, 2},
            {4, 0, 8, 4}
    };

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rtboard[i][j] != expected_rtboard[i][j]) {
                *message = TEST_SHIFT_DOWN_NOT_PASSED;
                return 1;
            }
        }
    }

    return 0;
}

int test_shift_up(char **message) {
    int score = 0;
    int rtboard[SIZE][SIZE] = {
            {2, 0, 4, 0},
            {4, 0, 0, 4},
            {0, 0, 0, 2},
            {0, 0, 4, 4}
    };

    shift_up(rtboard, &score);

    int expected_rtboard[SIZE][SIZE] = {
            {2, 0, 8, 4},
            {4, 0, 0, 2},
            {0, 0, 0, 4},
            {0, 0, 0, 0}
    };

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rtboard[i][j] != expected_rtboard[i][j]) {
                *message = TEST_SHIFT_UP_NOT_PASSED;
                return 1;
            }
        }
    }
    return 0;
}

int test_shift_left(char **message) {
    int score = 0;
    int rtboard[SIZE][SIZE] = {
            {2, 0, 4, 0},
            {4, 0, 0, 4},
            {0, 0, 0, 2},
            {0, 0, 4, 4}
    };

    shift_left(rtboard, &score);

    int expected_rtboard[SIZE][SIZE] = {
            {2, 4, 0, 0},
            {8, 0, 0, 0},
            {2, 0, 0, 0},
            {8, 0, 0, 0}
    };

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rtboard[i][j] != expected_rtboard[i][j]) {
                *message = TEST_SHIFT_LEFT_NOT_PASSED;
                return 1;
            }
        }
    }

    return 0;
}

int test_shift_right(char** message) {
    int score = 0;
    int rtboard[SIZE][SIZE] = {
            {2, 0, 4, 0},
            {4, 0, 0, 4},
            {0, 0, 0, 2},
            {0, 0, 4, 4}
    };

    shift_right(rtboard, &score);

    int expected_rtboard[SIZE][SIZE] = {
            {0, 0, 2, 4},
            {0, 0, 0, 8},
            {0, 0, 0, 2},
            {0, 0, 0, 8}
    };

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rtboard[i][j] != expected_rtboard[i][j]) {
                *message = TEST_SHIFT_RIGHT_NOT_PASSED;
                return 1;
            }
        }
    }
    return 0;
}

int is_game_over(int rboard[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rboard[i][j] == 0) {
                return 0;
            }
            if (j < SIZE - 1 && rboard[i][j] == rboard[i][j + 1]) {
                return 0;
            }
            if (i < SIZE - 1 && rboard[i][j] == rboard[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int test_is_game_over(int rboard[SIZE][SIZE], char** message) {
    generete_new_numb(rboard);

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            rboard[i][j] = 2;
        }
    }

    if (is_game_over(rboard)) {
        *message = TEST_IS_GAME_OVER_NOT_PASSED;
        return 1;
    }

    int rttboard[SIZE][SIZE] = {
            {128, 64, 8, 2},
            {32, 4, 2, 8},
            {2, 8, 4, 2},
            {64, 32, 16, 8}
    };

    if (!is_game_over(rttboard)) {
        *message = TEST_IS_GAME_OVER_NOT_PASSED;
        return 1;
    }
    return 0;
}

int test_generete_new_numb(int board[SIZE][SIZE], char** message) //„ÂÌÂ‡ˆËˇ ˜ËÒÎ‡ ‚ ÒÎÛ˜‡ÈÌÓÏ ÏÂÒÚÂ
{
    time_t t1; srand((unsigned)time(&t1));
    int b;
//b = rand() % 2;
//while (b < 1)
    //b = rand() % 2;
    char filename[] = "random.txt";
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%d", b);
    fclose(fp);
    int c = 0;
    fp = fopen(filename, "r");
    fscanf(fp, "%d", &c);
    fclose(fp);
    if (c != 0)
    {
        return 0;
    }
    else
    {
        *message = TEST_GENRATE_NEW_NUMB_NOT_PASSED;
        return 1;
    }
}


int testfirst(char** message)
{
    if (test_shift_down(message) == 1)
    {
        return 1;
    }
    if (test_shift_left(message) == 1)
    {
        return 1;
    }
    if (test_shift_up(message) == 1)
    {
        return 1;
    }
    if (test_shift_right(message) == 1)
    {
        return 1;
    }
    if (test_is_game_over(rboard, message) == 1)
    {
        return 1;
    }
    if (test_generete_new_numb(rboard, message) == 1)
    {
        return 1;
    }
    return 0;
}


