#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"

enum IntroGameMode {INTRO_EASY, INTRO_NORMAL, INTRO_HARD};
enum IntroSize {intro_small, intro_normal, intro_big};


class IntroController {
    bool finished = false;
    IntroView & view;
    IntroGameMode introGameMode;
    IntroSize introSize;
public:
    IntroSize getIntroSize() const;

public:
    IntroGameMode getIntroGameMode() const;

    // IntroModel & model;
public:
    IntroController(IntroView & view);

    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}

};


#endif // INTROCONTROLLER_H
