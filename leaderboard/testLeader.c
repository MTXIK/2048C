#include <stdio.h>
#include <string.h>
#include "leaderboard.h"
#include "testLeader.h"

#define MAX_USERS 10
#define MAX_SIZE 20

char ERR_OF_FSCORE_OPEN[] = "File for function FullScore not found";
char ERR_OF_FSCORE_TEST[] = "Test FullScore not passed";
char ERR_OF_SCORE_OPEN[] = "File for function Score not found";
char FSCORE_TEST_OK[] = "Test Fscore has passed succesfully";
char SCORE_TEST_OK[] = "Test Score has passed succesfully";

int test_getFullScore(char** message) {
    char filename[] = "scores.txt";
    char name[] = "Player835";
    int score = 10245;

    getFullScore(filename, name, score);

    // Проверка содержимого файла
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        *message = ERR_OF_FSCORE_OPEN;
        return 1;
    }

    char user_names[MAX_USERS][MAX_SIZE];
    int user_scores[MAX_USERS];
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        fscanf(fp, "%s %d", user_names[i], &user_scores[i]);
    }

    fclose(fp);

    // Проверка добавленного пользователя
    int user_found = 0;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(user_names[i], name) == 0 && user_scores[i] == score) {
            user_found = 1;
            break;
        }
    }

    if (user_found) {
        *message = FSCORE_TEST_OK;
        return 0;
    } else {
        *message = ERR_OF_FSCORE_TEST;
        return 1;
    }
}

int test_Score(char** message) {
    char filename[] = "scores.txt";
    int nums[MAX_USERS];
    char names[MAX_USERS][MAX_SIZE];

    Score(filename, nums, names);

    // Проверка содержимого файла
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        *message = ERR_OF_SCORE_OPEN;
        return 1;
    }

    int row = 0;
    char buffer[MAX_SIZE + 5];
    while (fgets(buffer, MAX_SIZE + 5, fp)) {
        sscanf(buffer, "%s %d", names[row], &nums[row]);
        row++;
    }

    fclose(fp);

    *message = SCORE_TEST_OK;
    return 0;   
}

int test_leaderBoard(char** message)
{
    if (test_getFullScore(message) == 1)
    {
        return 1;
    }
    if (test_Score(message) == 1)
    {
        return 1;
    }
    return 0;
}