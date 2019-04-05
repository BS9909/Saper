//
// Created by Bartek on 30.03.2019.
//

#include "MSGui.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

MSGui::MSGui(int rectangle_width, int rectangle_high, int gap, int rectangle_size, int window_width, int window_high, int row_shift, int column_shift,Minesweeperboard &msb)
:msb(msb),
window(sf::VideoMode(window_width,window_high), "Window", sf::Style::Default),
rectangle(sf::Vector2f(rectangle_size,rectangle_size)) {
    this->rectangle_size = rectangle_size;
    this->window_width = window_width;
    this->window_high = window_high;
    this->row_shift = row_shift;
    this->column_shift = column_shift;
    this->rectangle_high = rectangle_high;
    this->rectangle_width = rectangle_width;
    this->gap = gap;
    sf::Event event;
    rectangle.setFillColor(sf::Color::Blue);
    window.clear(sf::Color::Black);
    rectangle.setOutlineThickness(-1);
    rectangle.setOutlineColor(sf::Color::Black);

}
void MSGui::note_board() {
    for (int i = 0; i <rectangle_high; ++i) {
        for (int j = 0; j < rectangle_width; ++j) {
            rectangle.setPosition(row_shift+i*(gap+rectangle_size), column_shift+j*(gap+rectangle_size));
            rectangleBoard[i][j] = rectangle;
            window.draw(rectangleBoard[i][j]);
        }
    }
}
void MSGui::controllEvents() {
    sf::Event event;
    while (window.pollEvent(event)){
        if(event.type == sf::Event::EventType::Closed)
            window.close();
        for (int i = 0; i <rectangle_high; ++i) {
            for (int j = 0; j < rectangle_width; ++j) {
                auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
                auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
                if(rectangleBoard[i][j].getGlobalBounds().contains(translated_pos)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                        msb.revealField(i,j);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                        msb.toggleFlag(i,j);
                    }
                }
            }
        }
    }
}
void MSGui::texture_on() {
    if(!tex1.loadFromFile("1.jpg")) std::cout<<"1 ERROR!"<<std::endl;
}
void MSGui::display() {
    for (int i = 0; i < rectangle_high; ++i) {
        for (int j = 0; j < rectangle_width; ++j) {
            if (msb.getFieldInfo(i, j) == ' ')
                rectangleBoard[i][j].setFillColor(sf::Color::Red);
            if (msb.getFieldInfo(i, j) == 'F')
                rectangleBoard[i][j].setFillColor(sf::Color::Green);
            if (msb.getFieldInfo(i, j) == 'x')
                rectangleBoard[i][j].setFillColor(sf::Color::Yellow);
        }
    }
}


