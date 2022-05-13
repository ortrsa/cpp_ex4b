#include "Duke.hpp"
# include "Game.hpp"
using namespace coup;
const int FOREIGNAIDCOIN = 2;
const int MAXCOINS = 10;
const int TAXCOINS =3;

void Duke::block(Player & player){
    if(!alive){
        throw invalid_argument("you are dead!");
    }
    if(this_game.players().size() < 2){

        throw invalid_argument("need more players!");
    }
    if(!player.alive){
        throw invalid_argument("the player is dead"); 
    }
    if(player.my_move == "FOREIGNAID"){
                player.p_coins -=FOREIGNAIDCOIN;
                player.move_on = NULL;
                player.my_move = "";
            }else{
                throw invalid_argument("cant block");
            }
}
void Duke::tax(){
    check();
    if(p_coins < MAXCOINS){
        p_coins += TAXCOINS;

    }else{
        throw invalid_argument("you have to many coins");
    }
    this_game.next_turn();
};



