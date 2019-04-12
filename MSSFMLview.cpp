//
// Created by Bartek on 02.04.2019.
//

#include "MSSFMLview.h"
#include "Minesweeperboard.h"
#include <vector>
#include <cmath>
#include <cctype>

#include <SFML/Graphics.hpp>

MSSFMLview::MSSFMLview(int squarsize,Minesweeperboard &msb,int square_position_x,int square_position_y,sf::RenderWindow &win): msb(msb),
win(win)
{
    this->squaresize = squarsize;
    this->square_position_x = square_position_x;
    this->square_position_y = square_position_y;
}
void MSSFMLview::draw() {
    //Ustawiam parametry kwadratów
    sf::CircleShape square(squaresize,4);
    square.rotate(45);
    //Ustawiam czcionke
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    //Ustawiam parametry czcionki:
    text.setCharacterSize(50);
    text.setOutlineThickness(-2);
    text.setOutlineColor(sf::Color::Cyan);
    text.setCharacterSize(squaresize);
    text.setFillColor(sf::Color::Blue);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color::Red);
    text.setFont(font);
    //Dwie pętle for które odpowiadają za narysowanie siatki
    //UWAGA! Parametry j,i są w odwróconej kolejności dla getFieledinfo i dla rysowania siatki
    //wynika to z innej specyfikacjii funkcjii, getFieled info działa na bazie tablicy dwuwymiarowej która inkrementuje
    //w kolejności najpier po rzad 0->wszystkie kolumny w rzedzie 0->rzad1...
    //square.setPosition działa dokładnie na odwrót przez co należało zamienić parametry pętli.
    for (int j = 0; j < msb.getBoardHeight(); ++j) {
        for (int i = 0; i < msb.getBoardWidth(); ++i) {
            //Tworzenie kwadratów i nadawanie im początkowych wartość
            square.setPosition(square_position_y + i*(squaresize*2)/pow(2, 0.5), square_position_x + j*(squaresize*2)/pow(2, 0.5));
            squareBox.push_back(square);
            square.setFillColor(sf::Color::Black);
            square.setOutlineThickness(-1);
            square.setOutlineColor(sf::Color::Red);;
            win.draw(square);
            //Trzy ify, ustawiają odpowiednią kolor bądź napis dla wartości zwracanych przez getFieledInfo
            //które nie są liczbą.
            if(msb.getFieldInfo(j,i)=='F') {
                square.setFillColor(sf::Color::Green);
                win.draw(square);
            }
            if(msb.getFieldInfo(j,i)=='x') {
                square.setFillColor(sf::Color::Red);
                win.draw(square);
            }
            if(msb.getFieldInfo(j,i)==' '){
                text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                text.setString("0");
                win.draw(text);
            }
            //Ustawianie napisu dla countMainsAround(isDigit)
            if(isdigit(msb.getFieldInfo(j,i))){
                switch (msb.getFieldInfo(j,i)){
                    case '1': text.setString("1");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        win.draw(text);
                        break;
                    case '2': text.setString("2");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '3': text.setString("3");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '4': text.setString("4");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '5': text.setString("5");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '6': text.setString("6");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '7': text.setString("7");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;
                    case '8': text.setString("8");
                        text.setPosition(square_position_y-10+i*sqrt(2)*squaresize,square_position_x+j*sqrt(2)*squaresize+0.8*squaresize);
                        win.draw(text);
                        break;

                }
            }

        }
    }
}

sf::RenderWindow &MSSFMLview::getWindow()  {
    return win;
}
const std::vector<sf::CircleShape>& MSSFMLview::getSquareBox() {
    return squareBox;
}

