#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>      


Board::Board()
{
    std::iota(this->state.begin(), this->state.end(), 0);
}

void Board::printBoard() {

    std::system("clear");

    printBorder();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
        
            std::cout << "| " << intToChar(this->state[i * WIDTH + j]) << " ";
        
        }
        std::cout << "|" << std::endl;
        printBorder();
    }
}

void Board::down() {

    int pos = blankPosition(this->state);

    if (pos < WIDTH) {
        return;
    }
    else {
        state[pos] = state[pos - WIDTH];
        state[pos - WIDTH] = 0;
    }
    
}

void Board::up() {

    int pos = blankPosition(this->state);

    if (pos > 11) {
        return;
    }
    else {
        state[pos] = state[pos + WIDTH];
        state[pos + WIDTH] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition(this->state);

    if (pos % WIDTH == 0) {
        return;
    }
    else {
        state[pos] = state[pos - 1];
        state[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition(this->state);

    if (pos % WIDTH == 3) {
        return;
    }
    else {
        state[pos] = state[pos + 1];
        state[pos + 1] = 0;
    }
    
}

void Board::randomize() {

    std::random_device rd;
    std::mt19937 rand_gen(rd());

    std::shuffle(this->state.begin(), this->state.end(), rand_gen);
    
    if (!isValid15(this->state)) {
        this->correct();
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
    
    for (int i = 0; i < SIZE - 1; i++) {
        if (i+1 != this->state[i]) {
            return false;
        }
    }
    return this->state[SIZE] == 0;
}


bool isValid15(std::array<int, SIZE> state) {

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

int boardInversions(std::array<int, SIZE> state) {
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

int blankPosition(std::array<int, SIZE> state) {

    for (int i = 0; i < 16; i++) {
       if (state[i] == 0) {
           return i;
       } 
    }
    return -1;
}

int blankRow(std::array<int, SIZE> state) {
    return blankPosition(state)/WIDTH + 1;
}

std::string border =         "+---+---+---+---+";

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




