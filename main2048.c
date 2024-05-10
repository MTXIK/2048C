#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "first/first.h"
#include "leaderboard/leaderboard.h"
#include "UI/UI.h"

int main() {
    int board[4][4] = {0};
    int score = 0;
    char player_name[MAX_SIZE];
    char file_name[100] = "/Users/mtx/Documents/all/scores.txt";
    char choice_menu;
    char glob;

    srand(time(NULL)); // инициализация генератора случайных чисел

    logo();


    while (choice_menu != 'q'){
        printMenu();
        choice_menu = getVariantMenu();
        system("clear");
        switch (choice_menu) {
            case 'w':
                // начать новую игру
                generete_new_numb(board);
                nick();
                printf("Введите ваше имя: ");
                scanf("%s", player_name);
                system("clear");
                generete_new_numb(board);
                while (!game_over(board) && glob != 'q') {
                    printf("                  %i pts \n", score);
                    map(board); // выводим текущее состояние игрового поля и очки
                    controls(); // выводим инструкции управления
                    char move = getVariantMenu(); // получаем действие от пользователя
                    system("clear");
                    switch(move) {
                        case 'a':
                            shift_left(board, &score);
                            break;
                        case 'd':
                            shift_right(board, &score);
                            break;
                        case 'w':
                            shift_up(board, &score);
                            break;
                        case 's':
                            shift_down(board, &score);
                            break;
                        case 'q':
                            glob = 'q';
                            break;
                        default:
                            break;
                    }
                    generete_new_numb(board); // добавляем на поле новое число
                }
                printf("                  %i pts \n", score);
                map(board);
                gameOver();
                printf("Конец игры. %s, ваш счет равен: %d pts\n",player_name, score);
                printf("Если вы побили рекорд, то ваш счет будет сохранен в таблице лидеров 😎!\n");
                getFullScore(file_name, player_name, score); // сохраняем результат игры в файл
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        board[i][j] = 0;
                    }
                }
                score = 0;
                glob = ' ';
                continue;
            case 'a':
                // показать таблицу результатов
                scoresUI(file_name);
                continue;
            case 'q':
                break;
            default:
                continue;
        }
        break;
    }
    goodbye();
    printf("До встречи!\n");
    return 0;
}
