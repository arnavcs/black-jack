// Card.cpp
// the cpp file that contains the member function of the card class
// Arnav Kumar

#include <string>
#include <vector>

#include "Card.h"

Card::Card () {
    p_suit = "h";
    p_value = "A";
    p_faceUp = false;
}

// sets the value of the card at initialization to have suit s, and value v, and is not faceup originally
Card::Card (int s, int v) {
    std::vector<std::string> Suit {"h", "d", "s", "c"}, Value {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    p_suit = Suit[s];
    p_value = Value[v]; 
    p_faceUp = false;
}

// gets the type of the card ex. 3h for 3 of hearts
std::string Card::getString () {
    if (p_faceUp) {
        return (p_value + p_suit);
    } else {
        return "XX";
    }
}

// returns true if the card is faceup, and false otherwise
bool Card::isFaceUp () {
    return p_faceUp;
}

// gets a vector of the possible number of points that the card is worth
std::vector<int> Card::getPoints () {
    std::vector<int> values;
    if (!p_faceUp) { // if the card is face down, don't add it
        values.push_back(0);
    } else if (p_value == "A") { // returns 1 and 11 if it is an ace
        values.push_back(1);
        values.push_back(11);
    } else if (p_value == "J" || p_value == "Q" || p_value == "K") { // returns 10 if the card is jack, queen, or king
        values.push_back(10);
    } else { // returns the value if the card is between 2 and 10
        values.push_back(std::stoi(p_value));
    }
    return values;
}

// flips the card
void Card::flip () {
    p_faceUp = !p_faceUp;
}