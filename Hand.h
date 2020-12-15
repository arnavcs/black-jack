// Hand.h
// the header file that defines the Hand class
// Arnav Kumar

#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>

#include "Card.h"

class Hand {
private:
    // all the cards that the player has in their hand
    std::vector<Card> p_hand;

public:
    // returns the private hand variable
    std::vector<Card>& getHand ();

    // adds a card to the hand of cards
    void addCard (Card card);

    // clears the hand to contain no cards
    void clear ();

    // gets the total of the cards in the hand. Returns the value closest to 21 (not exceeding)
    int getTotal ();

    // gets the string displayable version of the hand
    std::string getString (int space = 6);
};

#endif