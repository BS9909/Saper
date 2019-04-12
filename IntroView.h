#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>

class IntroView {
    sf::RectangleShape rect;
    sf::RectangleShape rect_easy_mode;
    sf::RectangleShape rect_normal_mode;
    sf::RectangleShape rect_hard_mode;

    sf::Font font;
    sf::Text txt;
    sf::Text txt_easy;
    sf::Text txt_normal;
    sf::Text txt_hard;
    sf::Text txt_play;

public:
    IntroView();

    void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
