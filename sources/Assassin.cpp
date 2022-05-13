#include "Assassin.hpp"
#include "Game.hpp"
using namespace coup;
const int COUPCOINS = 7;
const int ASSCOUP = 3;
void Assassin::coup(Player &player_to_coup){
    check();
    if(!player_to_coup.alive){
        throw invalid_argument("need more coins");
    }
    if(this->p_coins >=COUPCOINS){
    this->p_coins -= COUPCOINS;
    player_to_coup.alive = false;
    }
    else if(this->p_coins >=ASSCOUP){
    this->p_coins -= ASSCOUP;
    move_on = &player_to_coup;
    my_move = "AssCoup";
    player_to_coup.alive = false;
    }else{
        throw invalid_argument("need more coins");
    }

    this_game.next_turn();
};


