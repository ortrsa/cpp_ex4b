#ifndef _Conte
#define _Conte
#include "Game.hpp"
#include "Player.hpp"
#pragma once
namespace coup
{
    class Contessa : public Player{
    public:
        
        Contessa(Game &game,const string & name): Player(game,name){
            if(game.isrunning()){
                throw invalid_argument("cant add player");
            }
            Player::p_role = "Contessa";
            game.add_player(*this);
        };
        void block(Player &player);

    };
}
#endif