#include "hello.hpp"
#include "board.hpp"
#include "row.hpp"

#include <stdio.h>
#include <iostream>
#include <conio.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int main() {

    int tester [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    Board testerBoard(tester);
    testerBoard.correct();
    testerBoard.right();
    testerBoard.right();
    testerBoard.down();
    testerBoard.left();
    testerBoard.down();
    testerBoard.right();
    testerBoard.up();


    char ch=0;
    do {

        std::cout << "\033[2J\033[1;1H";
        std::cout << "Press Q to quit and W, A, S, or D to move.\n";
        testerBoard.printBoard();

        ch = std::getch();

        if (testerBoard.isSolved()) {
            std::cout << "Game over, you won! \n";
            return 0;
        }

        switch(ch)  {
            case KEY_RIGHT:
            case 'W':
            case 'w':
                testerBoard.up();
                break;
            case KEY_LEFT:
            case 'A':
            case 'a':
                testerBoard.left();
                break;
            case KEY_DOWN:
            case 's':
            case 'S':
                testerBoard.down();
                break;
            case KEY_UP:
            case 'D':
            case 'd':
                testerBoard.right();
                break;

        }

    } while (ch != 'Q' && ch!='q');
  
    return 0;
}
