#ifndef GAME
#define GAME

#include <iostream>
#include <vector>
#include "Player.hpp"

#pragma once
using std::string;
using std::vector;
using std::invalid_argument;
namespace coup
{
    class Player;
    class Game
    {
    
    public:

        
        vector<Player*> p_players;
        unsigned int turn_counter;
        unsigned int player_counter;
        bool running;

        Game(){
            running = false;
            turn_counter = 0;
            player_counter =0;
        };
        ~Game(){};
        bool isrunning() const;
        string turn();
        vector <string> players();
        string winner();
        void add_player(Player& p_player);
        void next_turn();
        void run_game();
        
    };
}
#endif