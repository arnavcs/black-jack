// House.h
// the header file that defines the House class
// Arnav Kumar

#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer {
private:

public:
    // returns true if the house is hitting
    bool isHitting ();

    // flips the first card of the house (to make it unknown or reveal it)
    void flipFirstCard ();
};

#endif