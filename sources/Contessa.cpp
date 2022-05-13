#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
using namespace coup;
using std::invalid_argument;

void Contessa::block(Player &player){
    if(!alive){
        throw invalid_argument("you are dead!");
    }
    if(this_game.players().size() < 2){

        throw invalid_argument("need more players!");
    }
    if(player.role() == "Assassin"){
        if(player.my_move == "AssCoup"){
                player.move_on->alive = true;
                player.move_on = NULL;
                player.my_move = "";
            }else{
                throw invalid_argument("cant block");
            }

    }else{
        throw invalid_argument("can block only assassin");
    }
};

