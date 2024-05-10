#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "test_UI.h"


void nick(){
    printf("\033[0;36m");
    printf("\n"
           "██╗    ██╗██╗  ██╗ ██████╗ ██████╗ \n"
           "██║    ██║██║  ██║██╔═══██╗╚════██╗\n"
           "██║ █╗ ██║███████║██║   ██║  ▄███╔╝\n"
           "██║███╗██║██╔══██║██║   ██║  ▀▀══╝ \n"
           "╚███╔███╔╝██║  ██║╚██████╔╝  ██╗   \n"
           " ╚══╝╚══╝ ╚═╝  ╚═╝ ╚═════╝   ╚═╝   \n"
           "                                   ");
    printf("\033[0m");
    printf("\n");

}
void goodbye(){
    printf("\033[0;32m");
    printf("\n"
           "   ____    U  ___ u   U  ___ u  ____    ____   __   __U _____ u \n"
           "U /\"___|u   \\/\"_ \\/    \\/\"_ \\/ |  _\"\\U | __\")u \\ \\ / /\\| ___\"|/ \n"
           "\\| |  _ /   | | | |    | | | |/| | | |\\|  _ \\/  \\ V /  |  _|\"   \n"
           " | |_| |.-,_| |_| |.-,_| |_| |U| |_| |\\| |_) | U_|\"|_u | |___   \n"
           "  \\____| \\_)-\\___/  \\_)-\\___/  |____/ u|____/    |_|   |_____|  \n"
           "  _)(|_       \\\\         \\\\     |||_  _|| \\\\_.-,//|(_  <<   >>  \n"
           " (__)__)     (__)       (__)   (__)_)(__) (__)\\_) (__)(__) (__) ");
    printf("\033[0m");
    printf("\n");
}
void gameOver(){
    printf("\033[0;31m");
    printf("\n"
           "  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  \n"
           " ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n"
           "▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n"
           "░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n"
           "░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n"
           " ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n"
           "  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n"
           "░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ \n"
           "      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     \n"
           "                                                     ░                   ");
    printf("\033[0m");
    printf("\n");
}
void logo()
{
    printf("\033[0;35m");
    printf("____/\\\\\\\\\\\\\\\\\\_________/\\\\\\\\\\\\\\_______________/\\\\\\________/\\\\\\\\\\\\\\\\\\____\n");
    printf(" __/\\\\\\///////\\\\\\_____/\\\\\\/////\\\\\\___________/\\\\\\\\\\______/\\\\\\///////\\\\\\__\n");
    printf("  _\\///______\\//\\\\\\___/\\\\\\____\\//\\\\\\________/\\\\\\/\\\\\\_____\\/\\\\\\_____\\/\\\\\\__\n");
    printf("   ___________/\\\\\\/___\\/\\\\\\_____\\/\\\\\\______/\\\\\\/\\/\\\\\\_____\\///\\\\\\\\\\\\\\\\\\/___\n");
    printf("    ________/\\\\\\//_____\\/\\\\\\_____\\/\\\\\\____/\\\\\\/__\\/\\\\\\______/\\\\\\///////\\\\\\__\n");
    printf("     _____/\\\\\\//________\\/\\\\\\_____\\/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\______\\//\\\\\\_\n");
    printf("      ___/\\\\\\/___________\\//\\\\\\____/\\\\\\__\\///////////\\\\\\//__\\//\\\\\\______/\\\\\\__\n");
    printf("       __/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\\///\\\\\\\\\\\\\\/_____________\\/\\\\\\_____\\///\\\\\\\\\\\\\\\\\\/___\n");
    printf("        _\\///////////////_____\\///////_______________\\///________\\/////////_____\n");
    printf("\n");
    printf("===================================================================================\n");
    printf("             Made by: Nikita Ponomarev, Pavel Sorokin, Sergey Dekker\n");
    printf("===================================================================================\n");
    printf("\033[0m");
    printf("\n");

}
void printMenu() {
    printf("┌─────────────────────────────────────────────────┐\n");
    printf("│                                                 │\n");
    printf("│            What do you want to do?              │\n");
    printf("│                                                 │\n");
    printf("│                 w. Start game                   │\n");
    printf("│               a. See leaderboard                │\n");
    printf("│                    q. Exit                      │\n");
    printf("│                                                 │\n");
    printf("└─────────────────────────────────────────────────┘\n");
}

void scoresUI(char *filename){
    FILE *fp;
    fp = fopen(filename, "r");
    char s[20][80];
    for (int i = 0; i < 20; i++){
        fscanf(fp, "%s", s[i]);
    }
    printf("┌─────────────────────────────────────────────────┐\n");
    printf("                                                   \n");
    printf("                   Users scores                    \n");
    for(int i = 0; i < 20; i += 2){
        printf("             %s's score ==  ",s[i]);
        printf("%s pts.\n",s[i+1]);

    }
    fclose(fp);
    printf("└─────────────────────────────────────────────────┘\n");
}

int getVariantMenu() {
    char variant;
    char s[100] = {0}; // строка для считывания введённых данных
    scanf("%s", s); // считываем строк
    while (sscanf(s, "%c", &variant) != 1 || (variant != 'w' && variant != 'a' && variant != 's' && variant != 'd' && variant != 'q')){
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }
    return variant;
}

void map(int arr[4][4]) {
    int i;
    int j;
    printf("┌─────────┬─────────┬─────────┬─────────┐\n");// map 2048
    for (i = 0; i <= 3; i++) {
        printf("│         │         │         │         │\n");
//        printf("|");

        for (j = 0; j <= 3; j++) {
            if (arr[i][j] == 0) {
                printf("│    .    ");
            } else if (arr[i][j] == 2) {
                printf("│    \033[0;32m%i\033[0m    ", arr[i][j]);
            }else if (arr[i][j] == 4) {
                printf("│    \033[0;92m%i\033[0m    ", arr[i][j]);
            }else if (arr[i][j] == 8) {
                printf("│    \033[0;93m%i\033[0m    ", arr[i][j]);
            }else if (arr[i][j] == 16) {
                printf("│    \033[0;33m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 32) {
                printf("│    \033[0;95m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 64) {
                printf("│    \033[0;35m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 128 ) {
                printf("│   \033[0;91m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 256) {
                printf("│   \033[0;31m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 512) {
                printf("│   \033[0;96m%i\033[0m   ", arr[i][j]);
            }else if (arr[i][j] == 1024) {
                printf("│   \033[0;36m%i\033[0m  ", arr[i][j]);
            }else if (arr[i][j] == 2048) {
                printf("│   \033[0;97m%i\033[0m  ", arr[i][j]);
            }
        }
        printf("│");
        if (i < 3) {
            printf("\n");
            printf("│         │         │         │         │\n");
            printf("├─────────┼─────────┼─────────┼─────────┤\n");
        }
        if (i == 3) {
            printf("\n");
            printf("│         │         │         │         │\n");
            printf("└─────────┴─────────┴─────────┴─────────┘\n");
        }
    }
}
void controls(){
    printf("\033[0;35m");
    printf("                 W = up\n");
    printf("       A = left  S = down  D = right\n");
    printf("                (Q = exit)\n");
    printf("\033[0m");
}

void printFull(int array[4][4], char* filename){
    char variant;
    do {
        logo();
        printMenu(); // выводим меню на экран

        variant = getVariantMenu(); // получаем номер выбранного пункта меню

        switch (variant) {
            case 'w':
                system("clear");
                logo();
                map(array);
                controls();
                break;

            case 'a':
                system("clear");
                logo();
                scoresUI(filename);
                break;
        }
        break;
    }while (variant != 'q');
}


