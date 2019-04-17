//
// Created by Bartek on 20.03.2019.
//

#ifndef SAPER0_2_MINESWEEPERBOARD_H
#define SAPER0_2_MINESWEEPERBOARD_H


enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Fieled{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class Minesweeperboard {
    Fieled board[100][100];
    int high,width;
    bool hasMine(int row, int column)const;
    GameState game_status;
    GameMode gameMode;
public:
    double getAmountsOfMines() const;

public:
    GameMode getMode() const;

private:
    bool firstMove;
public:
    bool isFirstMove() const;

public:
    Minesweeperboard(int width, int high,GameMode mode);
    void debug_display() const;
    void setMines();
    void newMine(int row, int column) ;
    int getBoardWidth()const ;
    int getBoardHeight()const ;
    int getMineCount() const;
    int countMinesAround(int row, int column) const;
    bool hasFlag(int row, int column) const;
    void toggleFlag(int row, int column);
    void revealField(int row, int column);
    bool isRevealed(int row, int column) const;
    GameState getGameState() const;
    char getFieldInfo(int row, int column)const ;
    void setColumn(int newColumn){width=newColumn;}
    void setRow(int newRow){width=newRow;}
    void setGameMode(GameMode newGameMode){gameMode = newGameMode;}
    void setNewParameters(int width, int height, GameMode gameMode);

};


#endif //SAPER0_2_MINESWEEPERBOARD_H
