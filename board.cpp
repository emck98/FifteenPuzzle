#include "board.hpp"
#include <iostream>


Board::Board(int* arr) {
    state = arr;
}
/*
std::string blankRowString = "|   |   |   |   |";
std::string border = "+---+---+---+---+";
*/

void Board::printBoard() {

    int * arr = this->state;

    printBorder();

    std::string one = "|   |   |   |   |";

    one[2] = intToChar(arr[0]);
    one[6] = intToChar(arr[1]);
    one[10] = intToChar(arr[2]);
    one[14] = intToChar(arr[3]);

    std::cout << one << "\n";

    printBorder();

    std::string two = "|   |   |   |   |";

    two[2] = intToChar(arr[4]);
    two[6] = intToChar(arr[5]);
    two[10] = intToChar(arr[6]);
    two[14] = intToChar(arr[7]);

    std::cout << two << "\n";

    printBorder();

    std::string three = "|   |   |   |   |";

    three[2] = intToChar(arr[8]);
    three[6] = intToChar(arr[9]);
    three[10] = intToChar(arr[10]);
    three[14] = intToChar(arr[11]);

    std::cout << three << "\n";

    printBorder();

    std::string four = "|   |   |   |   |";

    four[2] = intToChar(arr[12]);
    four[6] = intToChar(arr[13]);
    four[10] = intToChar(arr[14]);
    four[14] = intToChar(arr[15]);

    std::cout << four << "\n";

    printBorder();

}

void Board::down() {

    int pos = blankPosition(this->state);

    if (pos < 4) {
        return;
    }
    else {
        state[pos] = state[pos - 4];
        state[pos - 4] = 0;
    }
    
}

void Board::up() {

    int pos = blankPosition(this->state);

    if (pos > 11) {
        return;
    }
    else {
        state[pos] = state[pos + 4];
        state[pos + 4] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition(this->state);

    if (pos % 4 == 0) {
        return;
    }
    else {
        state[pos] = state[pos - 1];
        state[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition(this->state);

    if (pos % 4 == 3) {
        return;
    }
    else {
        state[pos] = state[pos + 1];
        state[pos + 1] = 0;
    }
    
}

void Board::correct() {
    if (!isValid15(this->state)) {
        int temp = this->state[0];
        this->state[0] = this->state[15];
        this->state[15] = temp;
    }
}

bool Board::isSolved() {
    int sol [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    for (int i = 0; i < 16; i++) {
        if (sol[i] != this->state[i]) {
            return false;
        }
    }
    return true;
}

bool isValid15(int * state) {

    if (boardInversions(state)%2 == 0) {
        if (blankRow(state)%2 == 0) {
            return true;
        }
    }
    else {
        if (blankRow(state)%2 != 0) {
            return true;
        }
    }
    return false;
}

int boardInversions(int * state) {
    int inversions = 0;
    
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1 ; j < 16; j++) {
            if (state[i] > state[j]) {
                if (state[i] * state[j] !=0) {
                    inversions++;
                }
            }
        }
    }
    return inversions;
}

int blankPosition(int* state) {

    for (int i = 0; i < 16; i++) {
       if (state[i] == 0) {
           return i;
       } 
    }
    return -1;
}

int blankRow(int* state) {
    return blankPosition(state)/4 + 1;
}


// Printing Functions

std::string blankRowString = "|   |   |   |   |";
std::string border = "+---+---+---+---+";


void printBorder() {
    std::cout << border << "\n";
}

char intToChar(int tile) {
    char ret;
    switch(tile) {
        case 0:
            ret = ' ';
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            ret = tile + '0';
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            ret = 'A' + (tile - 10);
            break;
        default:
              ret = '*';
    }
    return ret;
}




