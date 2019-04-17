#include "MinesweeperController.h"
#include <SFML/Graphics.hpp>
#include <cmath>

MinesweeperController::MinesweeperController(MinesweeperView &v, sf::RenderWindow &win,Minesweeperboard &msb, ScoreView &scoreView) :
view(v),
win(win),
mssfmLview(mssfmLview),
msb(msb),
scoreView(scoreView)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            msb.revealField(0,0);
            msb.revealField(1,1);// albo na odwrót - zależnie jak to sobie zdefiniowaliście
            if(msb.getGameState()==RUNNING)
                moveCounter++;
            if(msb.getGameState()==FINISHED_LOSS) {
                scoreView.setText("LOOSER");
                finished = true;
            }
            if(msb.getGameState()==FINISHED_WIN){
                scoreView.setText("You win!Congratulations");
                finished=true;
            }
        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
            msb.toggleFlag(5, 3); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
        }
    }

}
