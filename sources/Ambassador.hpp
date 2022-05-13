#ifndef _AMB
#define _AMB
#include "Game.hpp"
#include "Player.hpp"
#pragma once
namespace coup
{
    class Ambassador : public Player{
    public:

        Ambassador(Game &game,const string & name): Player(game,name){
            if(game.isrunning()){
                throw invalid_argument("cant add player");
            }
            Player::p_role = "Ambassador";
            game.add_player(*this);
        };
        void transfer(Player &player1, Player &player2);
        void block(Player &player);

    };
}
#endif