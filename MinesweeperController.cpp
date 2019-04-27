#include "MinesweeperController.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

MinesweeperController::MinesweeperController(MinesweeperView &v, sf::RenderWindow &win,Minesweeperboard &msb, ScoreView &scoreView, MSSFMLview & mssfmLview) :
view(v),
win(win),
mssfmLview(mssfmLview),
msb(msb),
scoreView(scoreView)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        div_t wiersz =  div((event.mouseButton.x - mssfmLview.getSquare_position_y()),mssfmLview.getSquaresize());
        div_t kolumna =  div((event.mouseButton.y-mssfmLview.getSquare_position_x()),mssfmLview.getSquaresize());
        std::cout<<wiersz.quot<<std::endl;
        std::cout<<kolumna.quot<<std::endl;
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            msb.revealField(wiersz.quot, kolumna.quot); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
           // albo na odwrót - zależnie jak to sobie zdefiniowaliście
            if(msb.getGameState()==RUNNING)
                moveCounter++;
            if(msb.getGameState()==FINISHED_LOSS) {
                std::string _str = std::to_string(moveCounter);//konwersja z strony: https://4programmers.net/C/Konwersje_int_na_string_i_string_na_int
                scoreView.setRevealAmountText(_str);
                scoreView.setText("LOOSER");
                finished = true;
            }
            if(msb.getGameState()==FINISHED_WIN){
                std::string _str = std::to_string(moveCounter);//konwersja z strony: https://4programmers.net/C/Konwersje_int_na_string_i_string_na_int
                scoreView.setRevealAmountText(_str);
                scoreView.setText("Winner");
                finished=true;
            }
        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
            msb.toggleFlag(wiersz.quot, kolumna.quot); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
        }
    }
}


