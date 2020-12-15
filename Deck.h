// Deck.h
// the header file that defines the Deck class
// Arnav Kumar

#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
private:

public:
    // makes the deck of 52 cards
    void populate ();

    // shuffles the deck
    void shuffle ();

    // deals a card to a hand
    void deal (Hand &hand);

    // keeps hitting the player while they want to be and they don't bust
    void additionalCards (GenericPlayer &gp);
};

#endif