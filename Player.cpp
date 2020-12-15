// Player.cpp
// the cpp file that contains the member function of the player class
// Arnav Kumar

#include <iostream>

#include "Player.h"

// asks the player if they would like to hit and returns that
bool Player::isHitting () {
    // they can't hit if they have already busted
    if (isBusted()) {
        return false;
    }
    
    std::string s_temp;
    char c_temp;

    // keep asking if they want a hit while their response is invalid
    do {
        std::cout << getName() << ", do you want a hit? (Y/N): ";
        std::cin >> s_temp;

        // only looks at the first letter of response
        c_temp = s_temp[0];
        // changes uppercase to lowercase
        if (c_temp < 'a') {
            c_temp += ('a' - 'A');
        }
    } while (!(c_temp == 'y' || c_temp == 'n'));
    
    // returns if they want a hit
    if (c_temp == 'y') {
        return true;
    } else {
        return false;
    }
}

// Announces that the player won
void Player::win () {
    std::cout << getName() << " wins!" << std::endl;
}

// Announces that the player lost
void Player::lose () {
    std::cout << getName() << " loses." << std::endl;
}

// Announces that the player pushed
void Player::push () {
    std::cout << getName() << " pushes." << std::endl;
}