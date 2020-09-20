#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


class Board {
    private:
        std::vector<int> state;
        int width;

        bool isValid();
        int blankRow();
        int blankPosition();

    public:
        Board(int width);
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
        int boardInversions();
    
        friend bool operator==(const Board& b1, const Board& b2);
};

char intToChar(int tile);

#endif /* BOARD_HPP */
