#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class Board {
    private:
        std::vector<int> state;
        const int rows;
        const int cols;

    public:
        Board(int rows, int cols);
        void printBoard();
        void printRow(int row);
        void printBorder();
        bool isSolved();
        void correct();
        
        // movements
        void down();
        void up();
        void left();
        void right();
        
            
};

bool isValid15(std::vector<int> state);

int boardInversions(std::vector<int> state);

int blankRow(std::vector<int> state);

int blankPosition(std::vector<int> state);

char intToChar(int tile);

#endif /* BOARD_HPP */
