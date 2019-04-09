//
// Created by Bartek on 07.04.2019.
//
#include "MSSFMLview.h"
#include "MSTextController.h"
#include "Minesweeperboard.h"
#include <SFML/Graphics.hpp>

#ifndef SAPER0_2_MSMOUSEBUTTsON_H
#define SAPER0_2_MSMOUSEBUTTON_H


class MSMouseButton {
    MSSFMLview &sfmlView;
    Minesweeperboard &msb;
public:
    MSMouseButton(MSSFMLview &sfmlview,Minesweeperboard &msb);
    void controlEvents(sf::RenderWindow &win, sf::Event & event);

};


#endif //SAPER0_2_MSMOUSEBUTTON_H
