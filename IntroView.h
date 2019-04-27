#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>

class IntroView {
    sf::RectangleShape rect;

public:
    const sf::RectangleShape &getRect() const;

public:
    const sf::RectangleShape &getRect_easy_mode() const;

    const sf::RectangleShape &getRect_normal_mode() const;

    const sf::RectangleShape &getRect_hard_mode() const;

private:
    sf::RectangleShape rect_easy_mode;
    sf::RectangleShape rect_normal_mode;
    sf::RectangleShape rect_hard_mode;
    sf::RectangleShape rect_small_size;
    sf::RectangleShape rect_normal_size;
    sf::RectangleShape rect_big_size;
    sf::Font font;
public:
    const sf::RectangleShape &getRect_small_size() const;

    const sf::RectangleShape &getRect_normal_size() const;

    const sf::RectangleShape &getRect_big_size() const;

private:
    sf::Text txt;
    sf::Text dane;
    sf::Text album;
    sf::Text grupa;
    sf::Text txt_easy;
    sf::Text txt_normal;
    sf::Text txt_hard;
    sf::Text txt_play;
    sf::Text txt_small_size;
    sf::Text txt_normal_size;
    sf::Text txt_big_size;
    sf::RenderWindow &window;
    sf::Text setModeText;
    sf::Text setSizeText;
public:
    sf::Text text_mode;
public:
    sf::RenderWindow &getWindow() const;

public:
    IntroView(sf::RenderWindow &window);
    void draw(sf::RenderWindow &win);
    void setTextMode(std::string textMode){setModeText.setString(textMode);}
    void setTextSize(std::string textSize){setSizeText.setString(textSize);}
};


#endif // INTROVIEW_H
