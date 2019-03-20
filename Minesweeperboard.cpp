//
// Created by Bartek on 20.03.2019.
//


#include "Minesweeperboard.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <iostream>


Minesweeperboard::Minesweeperboard(int width, int high, GameMode mode) {
    srand(time(NULL));
    this ->width = width;
    this ->high = high;
    double amountsOfMines=0;
    int row=0, column=0;
    for(int i=0; i<high; i++){//row = i
        for(int j=0; j<width; j++){//column = j
            board[i][j].hasMine = false;
            board[i][j].hasFlag = false;
            board[i][j].isRevealed = false;

        }
    }
    if(mode==EASY){
        amountsOfMines = 0.1*width*high;
        for(int i=0; i<amountsOfMines; i++){
            row = rand()% high;
            column = rand()% width;
            board[row][column].hasMine = true;
        }
    }
    if(mode==NORMAL){
        amountsOfMines = 0.2*width*high;
        for(int i=0; i<amountsOfMines; i++){
            row = rand()% high;
            column = rand()% width;
            board[row][column].hasMine = true;
        }
    }
    if(mode==HARD){
        amountsOfMines = 0.3*width*high;
        for(int i=0; i<amountsOfMines; i++){
            row = rand()% high;
            column = rand()% width;
            board[row][column].hasMine = true;
        }
    }
    if(mode==DEBUG){
        for(int i=0; i<width; i++) board[0][i].hasMine = true; //wypelniamy kolumny minami w debug
        for(int i=0; i<high; i+=2) board[i][0].hasMine = true; //wypełniamy wiersze minami w debugu
        for(int i = 0; i<width && i<high; i++) board[i][i].hasMine = true;
    }
}
void Minesweeperboard::debug_display() const {
    for(int i=0; i<high; i++){
        for(int j=0; j<width; j++){
            if(board[i][j].hasMine) std::cout<<"[M";
            else std::cout<<"[.";
            if(board[i][j].isRevealed) std::cout<<"o";
            else std::cout<<".";
            if(board[i][j].hasFlag) std::cout<<"f]";
            else std::cout<<".]";
        }
        std::cout<<std::endl;
    }
}
int Minesweeperboard::getBoardWidth() const{
    return width;
}
int Minesweeperboard::getBoardHeight() const{
    return high;
}
bool Minesweeperboard ::hasMine(int row, int column) const {
    if(!(row>=0 && row<high && column>=0 && column<width)) return false;
    return board[row][column].hasMine;
}
int Minesweeperboard::countMinesAround(int row, int column) const {
    int counter =0;
    if(!(row>=0 && row < high && column>=0 && column < width)) return -1;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if(hasMine(i+row, j+column)) counter++;
        }
    }
    return counter;
}

bool Minesweeperboard::isRevealed(int row, int column) const {
    if(board[row][column].isRevealed) return true;
    return false;
}
void Minesweeperboard::revealField(int row, int column) {
    if ((row >= 0 && row < high && column >= 0 && column < width)) {
        for (int i = 0; i < high; i++) {
            for (int j = 0; j < width; j++) {
                if (!isRevealed(i, j) && board[row][column].hasMine) {
                    board[row][column].hasMine = false;
                    board[row][column].isRevealed = true;
                    int newRow=0;
                    int newColumn=0;
                    do{
                         newRow = rand()%high;
                         newColumn = rand()%width;
                    }while(board[newRow][newColumn].hasMine!=board[newRow][newColumn].isRevealed);
                }
                else if(!board[row][column].hasMine) board[row][column].isRevealed =true;
                else  game_status = FINISHED_LOSS;
            }

        }
    }
}
bool Minesweeperboard::hasFlag(int row, int column) const {
    if(!(row>=0 && row < high && column>=0 && column < width)) return 0;
    if(board[row][column].hasFlag) return true;
    return false;
}
void Minesweeperboard::toggleFlag(int row, int column) {
    if(hasFlag(row,column)) board[row][column].hasFlag = false;
    else if(!hasFlag(row,column)) board[row][column].hasFlag = true;
}
/*GameState Minesweeperboard::getGameState() const {
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            if(board[i][j].isRevealed && board[i][j].hasMine) game_status = FINISHED_LOSS;
            else if(!board[i][j].isRevealed && !board[i][j].hasFlag) game_status = RUNNING;
        }
    }
    game_status = FINISHED_WIN;
}*/
char Minesweeperboard::getFieldInfo(int row, int column) const {
    if(!(row>=0 && row < high && column>=0 && column < width)) return '#';
    if(board[row][column].isRevealed==0 && board[row][column].hasFlag==1) return  'F';
    if(board[row][column].isRevealed==0 && board[row][column].hasFlag==0) return  '_';
    if(board[row][column].isRevealed==1 && board[row][column].hasMine==1) return 'x';
    if(board[row][column].isRevealed==1 && countMinesAround(row,column)==0) return  ' ';
    if(board[row][column].isRevealed==1 && countMinesAround(row,column)>0) return static_cast<char>(countMinesAround(row,column)) ; //jawna konwersja int na char
    return 0;
}
