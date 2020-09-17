#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>      


int sorted_tester [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

std::array<int, 16> sorted_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0}; 

Board::Board() {
    state = sorted_tester;
    state2 = sorted_array;
}

void Board::printBoard() {

    std::system("clear");

    std::array<int, SIZE>  arr = this->state2;

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

    int pos = blankPosition(this->state2);

    if (pos < 4) {
        return;
    }
    else {
        state2[pos] = state2[pos - 4];
        state2[pos - 4] = 0;
    }
    
}

void Board::up() {

    int pos = blankPosition(this->state2);

    if (pos > 11) {
        return;
    }
    else {
        state2[pos] = state2[pos + 4];
        state2[pos + 4] = 0;
    }
    
}

void Board::right() {

    int pos = blankPosition(this->state2);

    if (pos % 4 == 0) {
        return;
    }
    else {
        state2[pos] = state2[pos - 1];
        state2[pos - 1] = 0;
    }
    
}

void Board::left() {

    int pos = blankPosition(this->state2);

    if (pos % 4 == 3) {
        return;
    }
    else {
        state2[pos] = state2[pos + 1];
        state2[pos + 1] = 0;
    }
    
}

void Board::randomize() {
    
    std::array<int, 16> randomized_array = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0}; 

    this->state2 = randomized_array;

    std::random_device rd;
    std::mt19937 rand_gen(rd());

    std::shuffle(randomized_array.begin(), randomized_array.end(), rand_gen);

    this->state2 = randomized_array;
    
    if (!isValid15(this->state2)) {
        this->correct();
    }

}

void Board::correct() {
    if (!isValid15(this->state2)) {
        int temp = this->state2[0];
        this->state2[0] = this->state2[15];
        this->state2[15] = temp;
    }
}

bool Board::isSolved() {
    int sol [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    

    for (int i = 0; i < SIZE; i++) {
        if (sol[i] != this->state2[i]) {
            return false;
        }
    }
    return true;
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
    return blankPosition(state)/4 + 1;
}

std::string blankRowString = "|   |   |   |   |";
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




