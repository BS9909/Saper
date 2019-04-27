#include "IntroController.h"
#include "GameManager.h"

IntroController::IntroController(IntroView &v,Minesweeperboard &msb,MSSFMLview &mssfmLview) : view(v),
msb(msb),
mssfmLview(mssfmLview)
{
    setting.gameMode=DEBUG;
}

void IntroController::handleEvent(sf::Event &event) {
        auto mouse_position = sf::Mouse::getPosition(view.getWindow());
        auto translated_pos = view.getWindow().mapPixelToCoords(mouse_position);
        if (view.getRect_easy_mode().getGlobalBounds().contains(translated_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                setting.gameMode=EASY;
                view.setTextMode("EASY");

            }
        }
        if (view.getRect_normal_mode().getGlobalBounds().contains(translated_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                setting.gameMode=NORMAL;
                view.setTextMode("NORMAL");

            }
        }
        if (view.getRect_hard_mode().getGlobalBounds().contains(translated_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                setting.gameMode=HARD;
                view.setTextMode("HARD");

            }
        }
    if(view.getRect_small_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            setting.column=10;
            setting.row=10;
            view.setTextSize("10x10");

        }
    }
    else if(view.getRect_normal_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            setting.column=20;
            setting.row=15;
            view.setTextSize("15x20");

        }
    }
    else if(view.getRect_big_size().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            setting.column=30;
            setting.row=20;
            view.setTextSize("20x30");

        }
    }
        if (view.getRect().getGlobalBounds().contains(translated_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if(setting.column!=0&&setting.row!=0&& setting.gameMode!=DEBUG) {
                    msb.setNewParameters(setting.column, setting.row, setting.gameMode);
                    mssfmLview.setNewParameters(setting.column, setting.row, setting.gameMode);
                    finished = true;
                }
            }
        }

}


