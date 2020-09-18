#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>      


Board::Board()
{
    std::iota(this->state.begin(), this->state.end(), 0);
    this->randomize();
}

void Board::printBoard() {

    std::system("clear");
    printBorder();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            std::cout << "| " << intToChar(this->state[i * WIDTH + j]) << " ";
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

    if (pos > SIZE - WIDTH - 1) {
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

    if (pos % WIDTH == WIDTH - 1) {
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
        this->state[0] = this->state[SIZE - 1];
        this->state[SIZE - 1] = temp;
    }
}

bool Board::isSolved() {
    
    for (int i = 0; i < SIZE - 1; i++) {
        if (i+1 != this->state[i]) {
            return false;
        }
    }
    return this->state[SIZE - 1] == 0;
}



/*
    "STATIC" METHODS
 */

bool isValid15(std::array<int, SIZE> state) {

    if (boardInversions(state) % 2 == 0) {
        if (blankRow(state) % 2 == 0) {
            return true;
        }
    }
    else {
        if (blankRow(state) % 2 != 0) {
            return true;
        }
    }
    return false;
}

int boardInversions(std::array<int, SIZE> state) {
    int inversions = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1 ; j < SIZE; j++) {
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

    for (int i = 0; i < SIZE; i++) {
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
    std::cout << border << std::endl;
}

char intToChar(int tile) {
    
    if (tile == 0) {
        return ' ';
    }
    else if (tile < 10) {
        return tile + '0';

    }
    else if (tile < SIZE) {
        return 'A' + tile - 10;

    }
    else {
        return '*';
    }

}




