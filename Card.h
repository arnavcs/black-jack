// Card.h
// the header file that defines the Card class
// Arnav Kumar

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string p_suit, p_value; // the suit and value of the card

    bool p_faceUp; // true if the card is faceup

public:
    Card ();

    // sets the value of the card at initialization to have suit s, and value v
    Card (int s, int v);

    // gets the type of the card ex. 3h for 3 of hearts
    std::string getString ();

    // returns true if the card is faceup, and false otherwise
    bool isFaceUp ();

    // gets the possible number of points that the card is worth
    std::vector<int> getPoints ();

    // flips the card
    void flip ();
};

#endif