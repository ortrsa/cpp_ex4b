#ifndef _PLAYER
#define _PLAYER
#pragma once
#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::invalid_argument;
#include "Game.hpp"

namespace coup
{
    class Game;
    class Player
    {
    public:
        string p_name;
        int p_coins;
        
        string p_role;
        bool alive; 
        string my_move;
        Player* move_on;
        Game& this_game;

        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        void set_id(int pid);
        void check() ;
        int get_id();
        string role() const;
        int coins() const;
        Player(Game& game, string name):p_name(std::move(name)),p_coins(0),alive(true), this_game(game){};

    };
}
#endif