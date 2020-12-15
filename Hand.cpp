// Hand.cpp
// the cpp file that contains the member function of the hand class
// Arnav Kumar

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "Card.h"
#include "Hand.h"

std::vector<Card>& Hand::getHand () {
    return p_hand;
}

// adds a card to the hand of cards
void Hand::addCard (Card card) {
    p_hand.push_back(card);
}

// clears the hand to contain no cards
void Hand::clear () {
    p_hand.clear();
    p_hand.resize(0);
}

// gets the total of the cards in the hand. Returns the value closest to 21 (not exceeding if possible)
int Hand::getTotal () {
    std::vector<int> allTotals, cardPoints, temp;
    allTotals.push_back(0);

    // make allTotals a vector whihc contains all possible total sums of values that the hand could take
    for (int i = 0; i < p_hand.size(); i++) {
        // resets the local vectors
        cardPoints.clear(); cardPoints.resize(0);
        temp.clear(); temp.resize(0);

        // temp is all combinations of existing potential totals and the values of the current card
        cardPoints = p_hand[i].getPoints();
        for (int j = 0; j < cardPoints.size(); j++) {
            for (int k = 0; k < allTotals.size(); k++) {
                temp.push_back(allTotals[k] + cardPoints[j]);
            }
        }

        // sets allTotals to temp
        allTotals.clear(); allTotals.resize(temp.size());
        allTotals = temp;
    }

    // finds the largest element of allTotals that doesn't bust, and returns it
    std::sort(allTotals.begin(), allTotals.end());

    int ind = 0;
    while ((allTotals[ind] < 21) && (ind + 1 < allTotals.size()) && (allTotals[ind + 1] < 21)) {ind++; }

    return allTotals[ind];
}

// gets the string displayable version of the player's hand 
std::string Hand::getString (int space /*= 6*/) {
    std::stringstream disp;
    bool isUnknown = false;

    for (int i = 0; i < p_hand.size(); i++) {
        disp << std::setw(space) << std::left << p_hand[i].getString(); 
        if (p_hand[i].getString() == "XX") {
            isUnknown = true;
        }
    }
    // if one of the cards is flipped over, don't write the value of the hand
    if (!isUnknown) {
        disp << '(' << getTotal() << ')';
    }

    return disp.str();
}