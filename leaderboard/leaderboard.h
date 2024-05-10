#ifndef leaderboard_h

#define leaderboard_h

#define MAX_SIZE 20


void getFullScore(
    char* filename, // имя файла
    char* name, // имя игока
    int score // количество очков, набранных игроком
);
void Score(
     char* filename, 
     int nums[], 
     char names[][MAX_SIZE]
);  

#endif