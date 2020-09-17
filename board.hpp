#ifndef BOARD_HPP
#define BOARD_HPP

#include <array> 

class Board {
    private:
        int * state;
        std::array<int, 16> state2;
        

    public:
        Board();
        void printBoard();
        void down();
        void up();
        void left();
        void right();
        void correct();
        void randomize();
        bool isSolved();

};

//std::array<int, 16> state
// bool isValid15(int * state);

// int boardInversions(int* state);

// int blankRow(int* state);

// int blankPosition(int* state);

bool isValid15(std::array<int, 16> state);

int boardInversions(std::array<int, 16> state);

int blankRow(std::array<int, 16> state);

int blankPosition(std::array<int, 16> state);

char intToChar(int tile);

void printBorder();

#endif /* BOARD_HPP */