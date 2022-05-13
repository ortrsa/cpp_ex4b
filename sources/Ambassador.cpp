#include "Ambassador.hpp"
#include "Game.hpp"
using namespace coup;
const int MAXCOINS = 10;
const int MINCOINS = 0;
const int COINSSTEAL = 2;
const int NUMOFPLAYERS = 2;

void Ambassador::transfer(Player &player1, Player &player2){
    check();
    if(!player1.alive || !player2.alive){
        throw invalid_argument("one (or more) of the player is dead"); 
    }
    if(player1.coins() == MINCOINS || player2.coins()==MAXCOINS ){
        throw invalid_argument("cant transfer"); 
    }
    player1.p_coins --;
    player2.p_coins ++;
    this_game.next_turn();
};
void Ambassador::block(Player &player){
    if(!alive){
        throw invalid_argument("you are dead!");
    }
    if(this_game.players().size() < NUMOFPLAYERS){

        throw invalid_argument("need more players!");
    }
    if(!player.alive){
        throw invalid_argument("the player is dead"); 
    }
    if(player.role() == "Captain"){
        if(player.my_move == "STEAL"){
                player.p_coins -=COINSSTEAL;
                player.move_on->p_coins+=COINSSTEAL;
                player.move_on = NULL;
                player.my_move = "";
            }else{
                throw invalid_argument("cant block");
            }

    }else{
        throw invalid_argument("can block only Captain");
    }
    
};


