#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "Minesweeperboard.h"
#include"MSSFMLview.h"
#include "ScoreView.h"

struct sIntroSetting {
    int column;
    int row;
    GameMode gameMode;
};


class IntroController {
    bool finished = false;
    IntroView & view;
    Minesweeperboard &msb;
    MSSFMLview &mssfmLview;
    sIntroSetting setting;

    // IntroModel & model;
public:
    IntroController(IntroView & view,Minesweeperboard &msb,MSSFMLview &mssfmLview);

    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
    void setFinished(bool check_finished){finished = check_finished;}
};


#endif // INTROCONTROLLER_H
