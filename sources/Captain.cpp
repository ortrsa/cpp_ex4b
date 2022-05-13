#include "Captain.hpp"
#include "Game.hpp"
using namespace coup;
const int COINSSTEAL = 2;

void Captain::steal(Player &player){
check();
if(!player.alive){
    throw invalid_argument("the player is dead");
}
if(player.p_coins == 1){
    p_coins ++;
    player.p_coins --;
    move_on = &player;
    my_move = "STEAL";
}else if(p_coins > 1){
    p_coins += COINSSTEAL;
    player.p_coins -= COINSSTEAL;
    move_on = &player;
    my_move = "STEAL";
}else{
    move_on = &player;
    my_move = "STEAL";
}
this_game.next_turn();
};

void Captain::block(Player &player){
    if(!alive){
        throw invalid_argument("you are dead!");
    }
    if(this_game.players().size() < 2){

        throw invalid_argument("need more players!");
    }
    if(!player.alive){
        throw invalid_argument("the player is dead");
    }
    
    if(player.my_move == "STEAL"){
            player.p_coins -= COINSSTEAL;
            player.move_on->p_coins += COINSSTEAL;
            player.move_on = NULL;
            player.my_move = "";
        }else if (player.my_move == "FOREIGNAID")
        {
            player.p_coins -= COINSSTEAL;
            player.move_on = NULL;
            player.my_move = "";
        }else{
             throw invalid_argument("can block only STEAL and FOREIGNAID");
        }
        

};


