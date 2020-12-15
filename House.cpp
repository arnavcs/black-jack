// House.cpp
// the cpp file that contains the member function of the house class
// Arnav Kumar

#include <iostream>

#include "House.h"

// returns true if the house is hitting
bool House::isHitting () {
    // hits if their current total is less than or equal to 16
    if (getTotal() <= 16) {
        // declares that the house hits
        std::cout << getName() << " hits. " << std::endl;
        return true;
    }
    // returns false if the house doesn't hit
    return false;
}

// flips the first card of the house (to make it unknown or reveal it)
void House::flipFirstCard () {
    // gets the house's hand, and flips the first card
    getHand()[0].flip();
}