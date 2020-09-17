#include "board.hpp"
#include <iostream>


Board::Board(int* arr) {
    state = arr;
}

void Board::printBoard() {

    int * arr = this->state;
    Row rowOne = Row(arr[0], arr[1], arr[2], arr[3]);
    Row rowTwo = Row(arr[4], arr[5], arr[6], arr[7]);
    Row rowThree = Row(arr[8], arr[9], arr[10], arr[11]);
    Row rowFour = Row(arr[12], arr[13], arr[14], arr[15]);

    printBorder();
    rowOne.printRow();
    printBorder();
    rowTwo.printRow();
    printBorder();
    rowThree.printRow();
    printBorder();
    rowFour.printRow();
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

int blankRow(int* state) {
    int row = -1;

    for (int i = 0; i < 16; i++) {
       if (state[i] == 0) {
           row = i/4 + 1;
           break;
       } 
    }
    return row;
}

int blankPosition(int* state) {

    for (int i = 0; i < 16; i++) {
       if (state[i] == 0) {
           return i;
       } 
    }
    return -1;
}




