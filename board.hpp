#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#define WIDTH 4

class Board {
    private:
        std::vector<int> state;
        int width;
        int height;

        bool isValid();
        int boardInversions();
        int blankRow();
        int blankPosition();

    public:
        Board(int height, int width);
        Board(Board &b);
        void printBoard();
        void printBorder();
        void down();
        void up();
        void left();
        void right();
        void correct();
        void randomize();
        bool isSolved();
        int ManhattanDistance();
    
        friend bool operator==(const Board& b1, const Board& b2);
};

char intToChar(int tile);

#endif /* BOARD_HPP */
