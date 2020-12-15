// Player.h
// the header file that defines the Player class
// Arnav Kumar

#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer {
private:
    
public:
    // asks the player if they would like to hit and returns thier descision
    bool isHitting ();

    // Announces that the player won
    void win ();

    // Announces that the player lost
    void lose ();

    // Anounces that the player pushed
    void push ();
};

#endif