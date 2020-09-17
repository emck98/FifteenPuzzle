#ifndef BOARD_HPP
#define BOARD_HPP

#include <array> 

#define SIZE 16

class Board {
    private:
        std::array<int, SIZE> state;
        

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

bool isValid15(std::array<int, SIZE> state);

int boardInversions(std::array<int, SIZE> state);

int blankRow(std::array<int, SIZE> state);

int blankPosition(std::array<int, SIZE> state);

char intToChar(int tile);

void printBorder();

#endif /* BOARD_HPP */
