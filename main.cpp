// main.cpp
// excecutes all the functions and allow the player to play the game
// in order to run the program, enter the following into the command line (in unix) "g++ main.cpp -o main Card.cpp Deck.cpp Game.cpp GenericPlayer.cpp Hand.cpp House.cpp Player.cpp"
// Arnav Kumar

#include <bits/stdc++.h>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Game.h"

using namespace std;

int main () {
    Game myGame;
    char playAgain;
    string temp;

    cout << "\t\tWelcome to Blackjack by Arnav Kumar!" << endl;

    // keeps calling the play function on myGame while they state that they want to play again
    do {
        cout << endl;
        myGame.play();

        // data sanitation to see if the user wants ot play again
        do {
            cout << "Would you like to play again? (Y/N):";
            cin >> temp;

            playAgain = temp[0];
            if (playAgain < 'a') {
                playAgain += 'a' - 'A';
            }
        } while (!(playAgain == 'y' || playAgain == 'n'));
    } while (playAgain == 'y');

    return 0;
}