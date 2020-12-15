// Game.cpp
// the cpp file that contains the member function of the game class
// Arnav Kumar

#include <string>
#include <climits>
#include <iostream>

#include "Game.h"

// returns the number of players in the game (from input)
int Game::getNumPlayers () {
    int i_temp;

    // keeps asking how many players they want while the number of players is invalid
    do {
        std::cout << "How many players? (1-7): ";
        std::cin >> i_temp;
    } while (!(i_temp > 0 && i_temp < 8));

    // returns the number of players
    return i_temp;
}

// returns the name of one of the players
std::string Game::getPlayerName () {
    std::string playerName;

    // takes the player name in as input
    std::cout << "Enter player name (No spaces): ";
    std::cin >> playerName;

    // returns the name of the player
    return playerName;
}

// starts the game
void Game::initialDeal () {
    // gives each player 2 cards
    for (Player &p : p_players) {
        for (int i = 0; i < 2; i++) p_deck.deal(p);
    }
    // gives the house 2 cards, and flips over the first one
    for (int i = 0; i < 2; i++) p_deck.deal(p_house);
    p_house.flipFirstCard();
}

// displays the number of points held by each player and the house currently
void Game::displayGameStatus () {
    // prints the player status for each player
    for (int i = 0; i < p_players.size(); i++) {
        std::cout << p_players[i].getPlayerString() << std::endl;
    }
    // prints the status of the house
    std::cout << p_house.getPlayerString() << std::endl;
}

// displays the winners
void Game::endGame () {
    if (p_house.isBusted()) { // if the house if busted, make any players who isn't busted a winner
        for (Player &p : p_players) {
            if (!p.isBusted()) {
                p.win();
            }
        }
    } else { // if the house isn't busted
        for (Player &p : p_players) {
            // if the player is busted, ignore, go to the next player
            if (p.isBusted()) {
                continue;
            }
            if (p.getTotal() > p_house.getTotal()) { // if the player has more points than the house, they win
                p.win();
            } else if (p.getTotal() == p_house.getTotal()) { // if the player has the same amount of points as the house, they push
                p.push();
            } else if (p.getTotal() < p_house.getTotal()) { // if the player has fewer points than the house, they lose
                p.lose();
            }
        }
    }
}

// plays the game once
void Game::play () {
    // resets anything from the previous round
    p_players.clear(); p_house.clear();

    // sets the number of players playing
    p_players.resize(getNumPlayers());

    // names all of the players
    for (int i = 0; i < p_players.size(); i++) {
        p_players[i].setName(getPlayerName());
    }
    // names the house
    p_house.setName("House");

    // populates and shuffles the deck
    p_deck.populate();
    p_deck.shuffle();

    // gives the players and house 2 cards initially
    initialDeal();

    // displays the current game status
    std::cout << std::endl;
    displayGameStatus();
    std::cout << std::endl;

    // allows all players to keep hitting while they want to
    for (int i = 0; i < p_players.size(); i++) {
        p_deck.additionalCards(p_players[i]);
        std::cout << std::endl;
    }

    // after all players hit, reveals the houses's first card
    p_house.flipFirstCard();
    std::cout << p_house.getPlayerString() << std::endl;

    // allows the house to hit
    p_deck.additionalCards(p_house);
    std::cout << std::endl;

    // displays the winners, losers and pushers
    endGame();
    std::cout << std::endl;
}