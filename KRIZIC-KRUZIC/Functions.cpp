#include <iostream>
#include "Header.h"
using namespace std;

void board(char square[10]) {

    system("cls");
    cout << "KRIZIC-KRUZIC" << endl;
   

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl;
}
void player_plays(char square[10], char x, char o) {
    int player = 0;


    do {
        do {
            
            cout << "Enter the square you want to fill (1-9)" << endl;
            cin >> player;
        } while (player > 9 || player < 1);





        if (square[player] != o && square[player] != x) {
            square[player] = x;

            return;
        }

    } while (true);

}




void player2_plays(char square[10], char x, char o) {
    int player2 = 0;

    do {
        do {

            
            cout << "Enter the square you want to fill (1-9)" << endl;
            cin >> player2;
        } while (player2 > 9 || player2 < 1);

        if (square[player2] != x && square[player2] != o) {
            square[player2] = o;
            return;
        }



    } while (true);
}
bool check_the_winner(char square[10]) {
    if ((square[1] == square[2] && square[2] == square[3]) || (square[4] == square[5] && square[5] == square[6]) ||
        (square[7] == square[8] && square[8] == square[9]) || (square[1] == square[5] && square[5] == square[9]) ||
        (square[3] == square[5] && square[5] == square[7]) || (square[1] == square[4] && square[4] == square[7]) ||
        (square[2] == square[5] && square[5] == square[8]) || (square[3] == square[6] && square[6] == square[9])) {
        cout << "WIN WIN WIN" << endl;


        return true;
    }

    return false;
}

bool draw(char square[10]) {
    if (!check_the_winner(square)) {
        cout << "draw" << endl;
        return true;
    }
    return false;
}

void comp_plays(char square[10], char x, char o) {
    int comp = 0;
    do {
        do {
            cout << "Comp plays" << endl;

            srand(time(NULL));
            comp = rand() % 9 + 1;
        } while (comp > 9 || comp < 1);

        if (square[comp] != x && square[comp] != o) {
            square[comp] = o;
            return;
        }



    } while (true);
}
bool play_again() {


    char ponovljeni_igrac = 0;
    cout << "Do you want to play again? y(Yes) / n(No) " << endl;
    do {
        cin >> ponovljeni_igrac;
        if (ponovljeni_igrac == 'y' || ponovljeni_igrac == 'Y')
             second_game();
        if (ponovljeni_igrac == 'n' || ponovljeni_igrac == 'N')
            return false;
    } while (ponovljeni_igrac != 'y' && ponovljeni_igrac != 'Y' && ponovljeni_igrac != 'n' && ponovljeni_igrac != 'N');
    return true;
}
int second_game() {
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
    return true;
}