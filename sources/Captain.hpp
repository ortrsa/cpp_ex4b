#ifndef _Cap
#define _Cap
#include "Game.hpp"
#include "Player.hpp"
#pragma once
namespace coup
{
    class Captain : public Player{
    public:

        Captain(Game &game,const string & name): Player(game,name){
            if(game.isrunning()){
                throw invalid_argument("cant add player");
            }
            Player::p_role = "Captain";
            game.add_player(*this);
        };
        void steal(Player &player);
        void block(Player &player);

    };
}
#endif