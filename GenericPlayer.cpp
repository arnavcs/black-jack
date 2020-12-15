// GenericPlayer.cpp
// the cpp file that contains the member function of the GenericPlayer class
// Arnav Kumar

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "GenericPlayer.h"

// sets the name of the player
void GenericPlayer::setName (std::string name) {
    p_name = name;
}

// gets the name of the player
std::string GenericPlayer::getName () {
    return p_name;
}

// gets the string displayable verison of the player state
std::string GenericPlayer::getPlayerString () {
    std::stringstream disp;

    // adds the players name
    disp << std::setw(12) << std::left << p_name;
    // adds the players hand and total points
    disp << getString();

    return disp.str();
}

// returns true if the player is busted
bool GenericPlayer::isBusted () {
    if (getTotal() > 21) {
        return true;
    }
    return false;
}

void GenericPlayer::bust () {
    if (!isBusted()) { // a safety net in case this was called unintentionally
        return;
    }
    // declares they have busted
    std::cout << p_name << " busted." << std::endl;
}