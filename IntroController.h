#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "Minesweeperboard.h"
enum IntroGameMode {INTRO_EASY, INTRO_NORMAL, INTRO_HARD};
enum IntroSize {intro_small, intro_normal, intro_big};



class IntroController {
    bool finished = false;
    IntroView & view;
    IntroSize introSize;
    IntroGameMode introGameMode;
    bool intromode= false;
    Minesweeperboard &msb;
public:
    bool isIntromode() const;

public:
    IntroGameMode getIntroGameMode() ;

public:
    IntroSize getIntroSize() const;
    // IntroModel & model;
public:
    IntroController(IntroView & view,Minesweeperboard &msb);

    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}

};


#endif // INTROCONTROLLER_H
