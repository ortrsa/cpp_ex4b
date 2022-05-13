#ifndef _Duke
#define _Duke
#include "Game.hpp"
#include "Player.hpp"

namespace coup
{
    class Duke : public Player{
    public:

        Duke(Game &game,const string &name): Player(game,name){
            if(game.isrunning()){
                throw invalid_argument("cant add player");
            }
            Player::p_role = "Duke";
            game.add_player(*this);
        };
        void block(Player & player);
        void tax();

    };
}
#endif