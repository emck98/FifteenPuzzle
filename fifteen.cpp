#include "board.hpp"
#include "solver.hpp"

#include <stdio.h>
#include <iostream>


int main() {

    Board testerBoard(2, 2);
    std::system("clear");
    std::cout << "Win in " << solve(testerBoard) << " moves" << std::endl;

    char ch;
    do {

        testerBoard.printBoard();
        if (testerBoard.isSolved()) {
            std::cout << "Game over, you won!" << std::endl;
            return 0;
        }

        std::cout << "Press Q to quit and W, A, S, or D to move.\n";
        ch = std::getchar();

        switch(ch)  {
            case 'W':
            case 'w':
                testerBoard.up();
                break;
            case 'A':
            case 'a':
                testerBoard.left();
                break;
            case 's':
            case 'S':
                testerBoard.down();
                break;
            case 'D':
            case 'd':
                testerBoard.right();
                break;

        }
        std::system("clear");
    } while (ch != 'Q' && ch!='q');
  
    return 0;
}
