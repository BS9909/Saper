#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>

class IntroView {
    sf::RectangleShape rect;
public:
    const sf::RectangleShape &getRect() const;

private:
    sf::RectangleShape rect_easy_mode;
    sf::RectangleShape rect_normal_mode;
    sf::RectangleShape rect_hard_mode;
    sf::Font font;
    sf::Text txt;
    sf::Text txt_easy;
    sf::Text txt_normal;
    sf::Text txt_hard;
    sf::Text txt_play;
    sf::RenderWindow &window;
public:
    sf::RenderWindow &getWindow() const;

public:
    IntroView(sf::RenderWindow &window);


    void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
