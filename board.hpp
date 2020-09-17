#ifndef BOARD_HPP
#define BOARD_HPP

#include "row.hpp"

class Board {
    private:
        int * state;
        // Row rowOne;
        // Row rowTwo;
        // Row rowThree;
        // Row rowFour;
       
    public:
        // Board();
        Board(int* arr);
        void printBoard();
        void down();
        void up();
        void left();
        void right();
        void correct();
        bool isSolved();

};

bool isValid15(int * state);

int boardInversions(int * state);

int blankRow(int* state);

int blankPosition(int* state);

#endif /* BOARD_HPP */