// GenericPlayer.h
// the header file that defines the GenericPlayer class
// Arnav Kumar

#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

#include <string>

#include "Hand.h"

class GenericPlayer : public Hand {
private:
    // the name of the player
    std::string p_name;

public:
    // to be overriden by child functions
    virtual bool isHitting () = 0;

    // sets the name of the player
    void setName (std::string name);

    // gets the name of the player
    std::string getName ();

    // gets the string displayable verison of the player
    std::string getPlayerString ();

    // returns true if the player has busted
    bool isBusted ();

    // prints that the player has busted
    void bust ();
};

#endif