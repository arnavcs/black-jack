// Deck.cpp
// the cpp file that contains the member function of the deck class
// Arnav Kumar

#include <random>
#include <algorithm>
#include <iostream>

#include "Deck.h"

// makes the deck of 52 cards
void Deck::populate () {
    // clears the current hand
    clear();
    for (int i = 0; i < 4; i++) { // all suits
        for (int j = 0; j < 12; j++) { // all values
            addCard(Card(i, j));
        }
    }
}

// shuffles the deck
void Deck::shuffle () {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(getHand().begin(), getHand().end(), g);
}

// deals a card to a hand
void Deck::deal (Hand &hand) {
    // flips the card
    getHand().back().flip();
    // adds the card to the hand
    hand.addCard(getHand().back());
    // removes the card from the deck
    getHand().pop_back();
}

// keeps hitting the player while they want to be and they don't bust
void Deck::additionalCards (GenericPlayer &gp) {
    while (gp.isHitting()) { // while they keep hitting
        // deal them one card
        getHand().back().flip();
        gp.addCard(getHand().back());
        getHand().pop_back();

        // print their player state
        std::cout << gp.getPlayerString() << std::endl;

        // bust them if they bust
        if (gp.isBusted()) {
            gp.bust();
        }
    }
}