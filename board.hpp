#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
    private:
        int * state;

    public:
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

class Row {
    private:
        int first;
        int second;
        int third;
        int fourth;

    public:
        Row();
        Row(int a, int b, int c, int d);
        void printRow();

};

char intToChar(int tile);
void printBorder();

#endif /* BOARD_HPP */