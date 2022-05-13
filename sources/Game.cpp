#include "Game.hpp"


namespace coup{

const int MAXPLAYERS = 6;
vector <string> Game::players()  {
    vector<std::string> players;
    for (auto & player : p_players)
    {
        if(player->alive){
            players.push_back(player->p_name);
        }
    }
    
    return players;
};
string Game::turn(){
    if(p_players.empty()){
        throw invalid_argument("0 players") ;////
    }
    return p_players.at(turn_counter)->p_name;
};
string Game::winner(){
    if(player_counter <=1){
        throw invalid_argument("add more players to play and win");
    }
    if(players().size()==1){
        return players().at(0);
    }

    throw invalid_argument("no winner");
    
    
};
void Game::add_player(Player& p_player){
    if(player_counter<MAXPLAYERS){
    this->p_players.push_back(&p_player);
    
    player_counter ++;
    }
    else{
        throw invalid_argument("max player is 6");
    }
    
};

void Game::next_turn(){
    run_game();
    turn_counter = (turn_counter+1) % player_counter;
    if(!p_players.at(turn_counter)->alive){
        next_turn();
    }
    
};
bool Game::isrunning() const{
    return running;
}

void Game::run_game(){
    running = true;
}
}

