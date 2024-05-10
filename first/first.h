/**
* @brief NewField функция генерации чисел в случайном месте
* @param board – матрица, в которой происходит игра
* @return функция не возвращает ничего
**/
void generete_new_numb(int board[4][4]);


/**
* @brief GetField(int vievboard[4][4]) функция прекращения
игры
* @param vievboard – матрица для отображения, в которую
записывается главная матрица
* @return функция не возвращает ничего
**/
void getfield(int vievboard[4][4]);

void shift_left(int board[4][4], int* score);

void print_board(int board[4][4], int* score);

void shift_right(int board[4][4], int* score);

void shift_up(int board[4][4], int* score);

void shift_down(int board[4][4], int* score);

int game_over(int board[4][4]);

