#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView(sf::RenderWindow &window): window(window) {
    if (!font.loadFromFile("arial.ttf")) {
        abort();
    }
    rect.setSize(sf::Vector2f(100, 100));
    rect.setPosition(100, 100);
    txt_play.setFont(font);
    txt_play.setFillColor(sf::Color::Red);
    txt_play.setString("Play");
    txt_play.setPosition(120,125);
    txt.setCharacterSize(20);

    txt.setFont(font);
    txt.setString("Intro");
    txt.setPosition(350, 20);
    txt.setOutlineThickness(4);
    txt.setOutlineColor(sf::Color::Magenta);
    txt.setFillColor(sf::Color::Cyan);
    txt.setCharacterSize(50);

    rect_easy_mode.setSize(sf::Vector2f(100,50));
    rect_easy_mode.setPosition(250,100);
    txt_easy.setFont(font);
    txt_easy.setString("Easy");
    txt_easy.setPosition(280,100);
    txt_easy.setFillColor(sf::Color::Red);
    txt_easy.setCharacterSize(20);

    rect_normal_mode.setSize(sf::Vector2f(100,50));
    rect_normal_mode.setPosition(250,175);
    txt_normal.setFont(font);
    txt_normal.setString("Normal");
    txt_normal.setPosition(265,175);
    txt_normal.setFillColor(sf::Color::Red);
    txt_normal.setCharacterSize(20);

    rect_hard_mode.setSize(sf::Vector2f(100,50));
    rect_hard_mode.setPosition(250,250);
    txt_hard.setFont(font);
    txt_hard.setString("Hard");
    txt_hard.setPosition(275,250);
    txt_hard.setFillColor(sf::Color::Red);
    txt_hard.setCharacterSize(20);

    auto mouse_position = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_position);
    if(rect.getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {

        }
    }
}

void IntroView::draw(sf::RenderWindow &win) {
    win.draw(rect);
    win.draw(txt_play);
    win.draw(txt);
    win.draw(rect_easy_mode);
    win.draw(txt_easy);
    win.draw(rect_normal_mode);
    win.draw(txt_normal);
    win.draw(rect_hard_mode);
    win.draw(txt_hard);
}

sf::RenderWindow &IntroView::getWindow() const {
    return window;
}

const sf::RectangleShape &IntroView::getRect() const {
    return rect;
}
