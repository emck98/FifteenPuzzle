#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>


Board::Board(Board &b)
: state(b.state), width(b.width), height(b.height)
{}

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
    
    if (!this->isValid()) {
        this->correct();
    }

}

void Board::correct() {
    
    if (!this->isValid()) {
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

bool operator==(const Board& b1, const Board& b2) {
    return b1.state == b2.state;
}

int Board::ManhattanDistance() {
    int sumDistance = 0;
    for (int i = 0; i < this->state.size(); i++) {
        int tile = this->state[i] == 0 ? this->state.size() : this->state[i];
        int dx = abs(i % this->width - (tile - 1) % this->width);
        int dy = abs(i / this->width - (tile - 1) / this->width);
        sumDistance += dx + dy;
    }
        return sumDistance;
}


bool Board::isValid() {

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

int Board::boardInversions() {
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

int Board::blankPosition() {

    for (int i = 0; i < this->state.size(); i++) {
       if (this->state[i] == 0) {
           return i;
       } 
    }
    return -1;
}

int Board::blankRow() {
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
