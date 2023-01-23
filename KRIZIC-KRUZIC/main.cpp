#include <iostream>
#include "Header.h"
using namespace std;
#include <time.h>


int main()
{
    char square[10];
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
    int number_of_moves = 9;
    char name[10];
    char second_name[10];


    char player_chooses = 0;
    do {
        cout << "DO YOU WANT TO PLAY AGAINST THE COMPUTER OR A FRIEND?" << endl;
        cout << "AGAINST COMPUTER CLICK c, AGAINST FRIEND CLICK f ?" << endl;
        cin >> player_chooses;
    } while (player_chooses != 'c' && player_chooses != 'C' && player_chooses != 'f' && player_chooses != 'F');
    cout << "FIRST PLAYER ENTER NAME: " << endl;
    cin >> name;

    if (player_chooses == 'f' || player_chooses == 'F') {
        cout << "SECOND PLAYER ENTER NAME" << endl;
        cin >> second_name;
    }
    if (player_chooses == 'c' || player_chooses == 'C') {
        board(square);
        
        for (int i = 1; i < 6; i++) {
            cout << name << " (X)  -  " << " COMP (O) " << endl << endl;
            cout << "Igra " << name << endl;
            player_plays(square, 'x', 'o');
            board(square);

            if (check_the_winner(square) == true) {
                cout << name << " IS WINNER" << endl;
                return play_again();
            }
            if (i == 5 && !check_the_winner(square)) {
                cout << "DRAW" << endl;
                return play_again();
            }


            cout << name << " (X)  -  " << " COMP (O) " << endl << endl;
            comp_plays(square, 'x', 'o');
            board(square);

            if (check_the_winner(square) == true) {
                cout << "COMP IS WINNER" << endl;
                return play_again();
            }
            if (i == 5 && !check_the_winner(square)) {
                cout << "DRAW" << endl;
                return play_again();
            }



        }
    }

    if (player_chooses == 'f' || player_chooses == 'F') {


        
        board(square);


        for (int i = 1; i < 6; i++) {
            cout << name << " (X)  -  " << second_name << " (O)" << endl;
            cout << name << " plays" << endl;
            player_plays(square, 'x', 'o');
            board(square);

            if (check_the_winner(square) == true) {
                cout << name << " IS WINNER" << endl;
                return play_again();
            }
            if (i == 5 && !check_the_winner(square)) {
                cout << "DRAW" << endl;
                return play_again();
            }

            cout << name << " (X)  -  " << second_name << " (O)" << endl;
            cout << second_name << " PLAYS" << endl;
            player2_plays(square, 'x', 'o');
            board(square);

            if (check_the_winner(square) == true) {
                cout << second_name << " IS WINNER" << endl;
                return play_again();
            }
            if (i == 5 && !check_the_winner(square)) {
                cout << "DRAW" << endl;
                return play_again();
            }



        }

    }








}


