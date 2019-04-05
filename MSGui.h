//
// Created by Bartek on 30.03.2019.
//

#ifndef SAPER0_2_MSGUI_H
#define SAPER0_2_MSGUI_H

#include "Minesweeperboard.h"
#include <SFML/Graphics.hpp>

class MSGui {
    int rectangle_size,window_width,window_high,row_shift,column_shift,rectangle_width,rectangle_high,gap;
    Minesweeperboard &msb;
    sf::RenderWindow window;
    sf::Texture tex1,tex2,tex3,tex4,tex5,tex6,tex7,tex8,texBomb;
    sf:: RectangleShape rectangleBoard[100][100];
    sf::RectangleShape rectangle;

public:
    MSGui(int rectangle_width, int rectangle_high,int gap, int rectangle_size, int window_width,int window_high,int row_shift, int column_shift, Minesweeperboard &msb);
    void display();
    void texture_on();
    void note_board();
    void controllEvents();
    void draw();

};


#endif //SAPER0_2_MSGUI_H
