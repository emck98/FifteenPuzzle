#include "board.hpp"
#include <iostream>
#include <numeric>


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


Board::Board(int rows, int cols)
: rows(rows), cols(cols), state(std::vector<int>(rows*cols)) {
    
    std::iota(this->state.begin(), this->state.end(), 0);
    std::random_shuffle(this->state.begin(), this->state.end());
    if (isValid15(this->state))
        this->correct();
}

void Board::printRow(int row) {

    std::cout << "|";
    
    for (int i = 0; i < this->cols; i++) {
           
        std::cout << " " << intToChar(this->state[this->cols * row + i]) << " |";
    
    }
    
    std::cout << std::endl;

}


void Board::printBorder() {

    std::cout << "+";
    for (int i = 0; i < this->cols; i++) {
        
        std::cout << "---+";
        
    }
    std::cout << std::endl;

}

void Board::printBoard() {
    
    this->printBorder();
    
    for (int i = 0; i < this->rows; i++) {
        
        this->printRow(i);
        this->printBorder();
        
    }

}

void Board::down() {

    int pos = blankPosition(this->state);

    if (pos < this->cols) {
        return;
    }
    else {
        state[pos] = state[pos - this->cols];
        state[pos - this->cols] = 0;
    }
    
}

void Board::up() {

    int pos = blankPosition(this->state);

    if (pos >= this->state.size() - this->cols) {
        return;
    }
    else {
        state[pos] = state[pos + this->cols];
        state[pos + this->cols] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition(this->state);

    if (pos % this->cols == 0) {
        return;
    }
    else {
        state[pos] = state[pos - 1];
        state[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition(this->state);

    if (pos % this->cols == this->cols - 1) {
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
        this->state[0] = this->state[this->state.size()];
        this->state[this->state.size()] = temp;
    }
}

bool Board::isSolved() {

    for (int i = 0; i < 16; i++) {
        if (i+1 != this->state[i]) {
            return false;
        }
    }
    return true;
}


// A board is solvable if:
//     the number of inversions is even AND the blank is on the 2nd or 4th row
//     the number of inversions is odd AND the blank is on the 1st or 3rd row


// TO BE REMOVED
const int COLS = 4;


bool isValid15(std::vector<int> state) {

    if (boardInversions(state) % 2 == 0) {
        if (blankRow(state) % 2 == 0) {
            return true;
        }
    }
    else {
        if (blankRow(state) % 2  != 0) {
            return true;
        }
    }
    return false;
}

int boardInversions(std::vector<int> state) {
    int inversions = 0;
    
    for (int i = 0; i < state.size(); i++) {
        for (int j = i + 1 ; j < state.size(); j++) {
            if (state[i] > state[j]) {
                if (state[i] * state[j] !=0) {
                    inversions++;
                }
            }
        }
    }
    return inversions;
}

int blankRow(std::vector<int> state) {
    int row = -1;

    for (int i = 0; i < state.size(); i++) {
       if (state[i] == 0) {
           row = i/COLS + 1;
           break;
       } 
    }
    return row;
}

int blankPosition(std::vector<int> state) {

    for (int i = 0; i < state.size(); i++) {
       if (state[i] == 0) {
           return i;
       } 
    }
    return -1;
}
