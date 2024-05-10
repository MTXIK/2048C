#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leaderboard.h"

#define MAX_USERS 10
#define MAX_SIZE 20

void getFullScore(
        char* filename, // имя файла
        char* name, // имя игрока
        int score // количество очков, набранных игроком
);

void Score(
        char* filename,
        int nums[],
        char names[][MAX_SIZE]
);

void getFullScore(char *filename, char *name, int score) {
    char user_names[MAX_USERS][MAX_SIZE];
    int user_scores[MAX_USERS], i, j;
    FILE *fp;

    fp = fopen(filename, "r+");

    if(fp == NULL)
    {
        printf("File for function FullScore not found.\n");
        return;
    }

    for(i = 0; i < MAX_USERS; i++)
    {
        fscanf(fp, "%s %d", user_names[i], &user_scores[i]);
    }

    fclose(fp);

    /* добавление нового пользователя */
    for(i = 0; i < MAX_USERS; i++)
    {
        if(score >= user_scores[i])
        {
            for(j = MAX_USERS - 1; j > i; j--)
            {
                strcpy(user_names[j], user_names[j-1]);
                user_scores[j] = user_scores[j-1];
            }
            strcpy(user_names[i], name);
            user_scores[i] = score;
            break;
        }
    }

    fp = fopen(filename, "w");

    for(i = 0; i < MAX_USERS; i++)
    {
        fprintf(fp, "%s %d\n", user_names[i], user_scores[i]);
    }

    fclose(fp);

    fp = fopen(filename, "r+");

    if(fp == NULL)
    {
        printf("File not found.\n");
        return;
    }
}

void Score(char* filename, int nums[], char names[][MAX_SIZE]) {
    FILE *fp;
    char buffer[MAX_SIZE+5];
    int row = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("This file not found: '%s'\n", filename);
        exit(1);
    }

    while (fgets(buffer, MAX_SIZE+5, fp)) { // Считываем каждую строку из файла
        sscanf(buffer, "%s %d", names[row], &nums[row]); // Считываем число и имя пользователя
        row++;
    }

    fclose(fp);
}
