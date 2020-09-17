#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#define WIDTH 4

class Board {
    private:
        std::vector<int> state;
        int width;
        int height;
        

    public:
        Board(int height, int width);
        void printBoard();
        void printBorder();
        void down();
        void up();
        void left();
        void right();
        void correct();
        void randomize();
        bool isSolved();

};

bool isValid(std::vector<int> state);

int boardInversions(std::vector<int> state);

int blankRow(std::vector<int> state);

int blankPosition(std::vector<int> state);

char intToChar(int tile);

#endif /* BOARD_HPP */
