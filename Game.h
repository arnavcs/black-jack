// Game.h
// the header file that defines the Game class
// Arnav Kumar

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Player.h"
#include "House.h"
#include "Deck.h"

class Game {
private:
    // the player, house, and deck of the game
    std::vector<Player> p_players;
    House p_house;
    Deck p_deck;

    // returns the number of players in the game
    int getNumPlayers ();

    // returns the name of one of the players
    std::string getPlayerName ();

    // starts the game
    void initialDeal ();

    // displays the number of points held by each player and the house currently
    void displayGameStatus ();

    // displays the winners
    void endGame ();

public:
    // plays the game once
    void play ();
};

#endif