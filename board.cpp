#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>


Board::Board(Board &b)
: state(b.state), width(b.width)
{}

Board::Board(int width)
: state(std::vector<int> (width*width)), width(width) {
    
    std::iota(this->state.begin(), this->state.end(), 0);
    this->randomize();
}

void Board::printBorder() const {
    
    for (int i = 0; i < this->width; i++) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}

void Board::printBoard() const {

    printBorder();

    for (int i = 0; i < this->width; i++) {
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

    int pos = this->blankPosition();

    if (pos < this->width) {
        return;
    }
    else {
        state[pos] = state[pos - this->width];
        state[pos - this->width] = 0;
    }
    
}

void Board::up() {

    int pos = this->blankPosition();

    if (pos > this->state.size() - this->width - 1) {
        return;
    }
    else {
        state[pos] = state[pos + this->width];
        state[pos + this->width] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition();

    if (pos % this->width == 0) {
        return;
    }
    else {
        state[pos] = state[pos - 1];
        state[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition();

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
    
    while(!this->isValid()) {
        this->randomize();
    }
}

void Board::correct() {
    
    if (!this->isValid()) {
        // swap first and second elements
        int temp = this->state[0];
        this->state[0] = this->state[1];
        this->state[1] = temp;
    }
}

bool Board::isSolved() const {
    
    for (int i = 0; i < this->state.size() - 1; i++) {
        if (i+1 != this->state[i]) {
            return false;
        }
    }
    return this->state[this->state.size() - 1] == 0;
}

int Board::ManhattanDistance() const {
    int sumDistance = 0;
    for (int i = 0; i < this->state.size(); i++) {
        int tile = this->state[i];
        if (tile == 0) continue;
        int dx = abs(i % this->width - (tile - 1) % this->width);
        int dy = abs(i / this->width - (tile - 1) / this->width);
        sumDistance += dx + dy;
    }
    return sumDistance;
}

// Works for N x N boards
bool Board::isValid() const {
    // N x N board where N is odd
    // only board inversions matter
    if (this->width % 2 != 0) {
        if (this->boardInversions() % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    // N x N boards where N is even
    // board inversion and postion of the blank square matter
    if (this->boardInversions() % 2 == 0) {
        if (this->blankRow() % 2 == 0) {
            return true;
        }
    }
    else if (this->blankRow() % 2 != 0) {
            return true;
    }
    return false;
}

int Board::boardInversions() const {
    int inversions = 0;
    
    for (int i = 0; i < this->state.size(); i++) {
        for (int j = i + 1 ; j < this->state.size(); j++) {
            if (this->state[i] > this->state[j]) {
                if (this->state[i] * this->state[j] !=0) {
                    inversions++;
                }
            }
        }
    }
    return inversions;
}

int Board::blankPosition() const {

    for (int i = 0; i < this->state.size(); i++) {
       if (this->state[i] == 0) {
           return i;
       } 
    }
    return -1;
}

int Board::blankRow() const {
    return this->blankPosition()/this->width + 1;
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
