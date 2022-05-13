#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
const int MAXCOINS = 10;
const int MINPLAYERS = 2;
const int FORGNCOINS = 2;
const int COUPCOINS = 7;

void Player::income(){
    check();
    if(p_coins<MAXCOINS){
        p_coins += 1;
        my_move = "income";
        this_game.next_turn();
    }else{
        throw invalid_argument("max coins is 10 use coup");
    }
    
};
void Player::foreign_aid(){
    check();
    if(p_coins<MAXCOINS){
        p_coins += FORGNCOINS;
        my_move = "FOREIGNAID";
        this_game.next_turn();
    }else{
        throw invalid_argument("max coins is 10 use coup or income"); 
    }
    
};
void Player::coup(Player &player){
    check();
    if(player.alive){
        if(p_coins>=COUPCOINS){
            player.alive = false;
            p_coins-=COUPCOINS;
            this_game.next_turn();
        }else{
            throw invalid_argument("need more coins");
        }
    }else{
        throw invalid_argument("player is alrady dead");
    }
    
};
string Player::role() const{
    return p_role;
};
int Player::coins() const{
    return p_coins;
};

void Player::check(){
    if(!alive){
        throw invalid_argument("you are dead!");
    }
    if(this_game.players().size() < MINPLAYERS){

        throw invalid_argument("need more players!");
    }
    if(this_game.p_players.at(this_game.turn_counter) != this){
        throw invalid_argument("this is not your turn!!");
    }
    move_on = NULL;
    my_move = "";
};

