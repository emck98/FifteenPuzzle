#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>      


Board::Board(int height, int width)
: state(std::vector<int> (height*width)), height(height), width(width) {
    
    std::iota(this->state.begin(), this->state.end(), 0);
    this->randomize();
}

void Board::printBorder() {
    
    for (int i = 0; i < this->width; i++) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}

void Board::printBoard() {

    std::system("clear");
    printBorder();

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            std::cout << "| ";
            std::cout << intToChar(this->state[i * this->width + j]);
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        printBorder();
    }
}

void Board::down() {

    int pos = blankPosition(this->state);

    if (pos < this->width) {
        return;
    }
    else {
        state[pos] = state[pos - this->width];
        state[pos - this->width] = 0;
    }
    
}

void Board::up() {

    int pos = blankPosition(this->state);

    if (pos > this->state.size() - this->width - 1) {
        return;
    }
    else {
        state[pos] = state[pos + this->width];
        state[pos + this->width] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition(this->state);

    if (pos % this->width == 0) {
        return;
    }
    else {
        state[pos] = state[pos - 1];
        state[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition(this->state);

    if (pos % this->width == this->width - 1) {
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
    
    if (!isValid(this->state)) {
        this->correct();
    }

}

void Board::correct() {
    
    if (!isValid(this->state)) {
        int temp = this->state[0];
        this->state[0] = this->state[this->state.size() - 1];
        this->state[this->state.size() - 1] = temp;
    }
}

bool Board::isSolved() {
    
    for (int i = 0; i < this->state.size() - 1; i++) {
        if (i+1 != this->state[i]) {
            return false;
        }
    }
    return this->state[this->state.size() - 1] == 0;
}


/*
    "STATIC" METHODS
 */

bool isValid(std::vector<int> state) {

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

int blankPosition(std::vector<int> state) {

    for (int i = 0; i < state.size(); i++) {
       if (state[i] == 0) {
           return i;
       } 
    }
    return -1;
}

int blankRow(std::vector<int> state) {
    return blankPosition(state)/WIDTH + 1;
}

char intToChar(int tile) {
    
    if (tile == 0)
        return ' ';
    else if (tile < 10)
        return tile + '0';
    else if (tile > 0)
        return 'A' + tile - 10;
    else
        return '*';
}
