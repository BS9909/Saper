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
    txt.setString("SAPER");
    txt.setPosition(300, 20);
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

    rect_small_size.setSize(sf::Vector2f(100,50));
    rect_small_size.setPosition(400,100);
    txt_small_size.setFont(font);
    txt_small_size.setString("10x10");
    txt_small_size.setPosition(425,100);
    txt_small_size.setFillColor(sf::Color::Red);
    txt_small_size.setCharacterSize(20);

    rect_normal_size.setSize(sf::Vector2f(100,50));
    rect_normal_size.setPosition(400, 175);
    txt_normal_size.setFont(font);
    txt_normal_size.setString("20x15");
    txt_normal_size.setPosition(425, 175);
    txt_normal_size.setFillColor(sf::Color::Red);
    txt_normal_size.setCharacterSize(20);

    rect_big_size.setSize(sf::Vector2f(100,50));
    rect_big_size.setPosition(400, 250);
    txt_big_size.setFont(font);
    txt_big_size.setString("30x20");
    txt_big_size.setPosition(425, 250);
    txt_big_size.setFillColor(sf::Color::Red);
    txt_big_size.setCharacterSize(20);

    dane.setFont(font);
    dane.setString("Bartosz Sochacki");
    dane.setPosition(700, 700);
    dane.setFillColor(sf::Color::Red);
    dane.setCharacterSize(20);

    album.setFont(font);
    album.setString("Nr. albumu: 249485");
    album.setPosition(700, 725);
    album.setFillColor(sf::Color::Red);
    album.setCharacterSize(20);

    grupa.setFont(font);
    grupa.setString("Wtorek 15:15");
    grupa.setPosition(700, 750);
    grupa.setFillColor(sf::Color::Red);
    grupa.setCharacterSize(20);

    text_mode.setFont(font);
    text_mode.setPosition(600,300);
    text_mode.setFillColor(sf::Color::Red);

    setModeText.setFont(font);
    setModeText.setPosition(175, 400);
    setModeText.setFillColor(sf::Color::Blue);
    setModeText.setCharacterSize(50);
    setModeText.setOutlineThickness(2);
    setModeText.setOutlineColor(sf::Color::Yellow);

    setSizeText.setFont(font);
    setSizeText.setPosition(175, 450);
    setSizeText.setFillColor(sf::Color::Blue);
    setSizeText.setCharacterSize(75);
    setSizeText.setOutlineThickness(2);
    setSizeText.setOutlineColor(sf::Color::Yellow);
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
    win.draw(rect_small_size);
    win.draw(txt_small_size);
    win.draw(rect_normal_size);
    win.draw(txt_normal_size);
    win.draw(rect_big_size);
    win.draw(txt_big_size);
    win.draw(text_mode);
    win.draw(dane);
    win.draw(album);
    win.draw(grupa);
    win.draw(setModeText);
    win.draw(setSizeText);
}

sf::RenderWindow &IntroView::getWindow() const {
    return window;
}

const sf::RectangleShape &IntroView::getRect() const {
    return rect;
}

const sf::RectangleShape &IntroView::getRect_easy_mode() const {
    return rect_easy_mode;
}

const sf::RectangleShape &IntroView::getRect_normal_mode() const {
    return rect_normal_mode;
}

const sf::RectangleShape &IntroView::getRect_hard_mode() const {
    return rect_hard_mode;
}

const sf::RectangleShape &IntroView::getRect_small_size() const {
    return rect_small_size;
}

const sf::RectangleShape &IntroView::getRect_normal_size() const {
    return rect_normal_size;
}

const sf::RectangleShape &IntroView::getRect_big_size() const {
    return rect_big_size;
}

