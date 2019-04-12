#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"

class IntroController {
    bool finished = false;
    IntroView & view;

    // IntroModel & model;
public:
    explicit IntroController(IntroView & iv);

    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};


#endif // INTROCONTROLLER_H
