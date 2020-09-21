#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


class Board {
    private:
        std::vector<int> state;
        int width;
        

        // print helper
        void printBorder() const;
    
        // modifiers
        void randomize();
        void correct();
    
        // validity checking helpers
        int blankRow() const;
        int blankPosition() const;

    public:
        Board(int width);
        Board(Board &b);
    
        void printBoard() const;
    
        // modifiers
        void down();
        void up();
        void left();
        void right();
    
        // metrics
        int ManhattanDistance() const;
        int boardInversions() const;
        bool isSolved() const;
        bool isValid() const;
    
        friend bool operator==(const Board& b1, const Board& b2) { return b1.state == b2.state; }
};

char intToChar(int tile);

#endif /* BOARD_HPP */
