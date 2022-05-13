#ifndef _Ass
#define _Ass
#pragma once
#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    class Assassin : public Player{
    public:
        
        Assassin(Game &game, string name) : Player(game,std::move(name)){
        if(game.isrunning()){
            throw invalid_argument("cant add player");
        }
        Player::p_role = "Assassin";
        game.add_player(*this);
        };
        void coup(Player &player) override;

    };
}
#endif