//
// Created by Nikita Ponomarev on 04.05.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "test_UI.h"
#include "UI.h"

char *PRINT_LOGO_ERROR = "Ошибка в логотипе!\n";
char *PRINT_MENU_ERROR = "Ошибка в отображении меню!\n";
char *PRINT_SCORES_ERROR = "Ошибка в отображении счета!\n";
char *PRINT_MAP_ERROR = "Ошибка в отображении карты! \n";
char *PRINT_CONTROLS_ERROR = "Ошибка в отображении подсказок управления! \n";
char *GET_VARIANT_ERROR = "Ошибка в получении кнопки \n";
const char *file = "test.txt";
const char  *file2 = "inputTest.txt";
const char *file3 = "userscores.txt";

int _testLogo(){
    freopen(file, "w", stdout);
    logo();
    fclose(stdout);
    freopen("/dev/tty", "a", stdout);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
    if(buf[1] != '['){
        return 1;
    }
    if(buf[21] != '_'){
        return 1;
    }
    return 0;
}

int _testScoresUI(){
    freopen(file, "w", stdout);
    scoresUI(file3);
    fclose(stdout);
    freopen("/dev/tty", "a", stdout);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
//    for (int i = 0; i < 1600; i++){
//        printf("%i",i);
//        printf("%c",buf[i]);
//        printf("%c",'\n');
//    }
    if(buf[157] != ' '){
        return 1;
    }
    if(buf[225] != 'U'){
        return 1;
    }
    return 0;
}

int _testPrintMenu(){
    freopen(file, "w", stdout);
    printMenu();
    fclose(stdout);
    freopen("/dev/tty", "a", stdout);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
    if(buf[157] != ' '){
        return 1;
    }
    if(buf[225] != 'W'){
        return 1;
    }
    return 0;
}

int _testMap(){
    int arr[4][4] = {{2,  2,    4,  2},
                     {16, 32,   64, 0},
                     {0,  2048, 0,  0,},
                     {0,  128,  0,  0}};
    freopen(file, "w", stdout);
    map(arr);
    fclose(stdout);
    freopen("/dev/tty", "a", stdout);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
//    for (int i = 0; i < 1600; i++){
//        printf("%i",i);
//        printf("%c",buf[i]);
//        printf("%c",'\n');
//    }
    if(buf[481] != '1'){
        return 1;
    }
    if(buf[504] != '3'){
        return 1;
    }
    return 0;
}


int _testControls(){
    freopen(file, "w", stdout);
    controls();
    fclose(stdout);
    freopen("/dev/tty", "a", stdout);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
    if(buf[1] != '['){
        return 1;
    }
    if(buf[93] != ')'){
        return 1;
    }
    return 0;
}

int _testGetVariantMenu(){
    freopen(file, "w", stdout);
    freopen(file2, "r", stdin);
    getVariantMenu();
    fclose(stdout);
    fclose(stdin);
    freopen("/dev/tty", "a", stdout);
    freopen("/dev/tty", "r", stdin);
    FILE *fp;
    fp = fopen(file, "r+");
    char buf[1600] = {0};
    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        return 1;
    }
    if(buf[0] != 'I'){
        return 1;
    }
    return 0;

}

int testUI(){
    if (_testLogo() == 1){
        printf("%s", PRINT_LOGO_ERROR);
        return 1;
    }
    if (_testScoresUI() == 1){
        printf("%s", PRINT_SCORES_ERROR);
        return 1;
    }
    if (_testPrintMenu() == 1){
        printf("%s", PRINT_MENU_ERROR);
        return 1;
    }
    if (_testMap() == 1){
        printf("%s", PRINT_MAP_ERROR);
        return 1;
    }
    if (_testControls() == 1){
        printf("%s", PRINT_CONTROLS_ERROR);
        return 1;
    }
    if (_testGetVariantMenu() == 1){
        printf("%s", GET_VARIANT_ERROR);
        return 1;
    }
    else{
        printf("Все тесты прошли проверку!\n");
        return 0;
    }
}

//int main(){
//    _testMap();
//}


