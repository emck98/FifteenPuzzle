#include "board.hpp"
#include "solver.hpp"

#include <stdio.h>
#include <iostream>


int main() {

    Board testerBoard(3);
    std::system("clear");
    int minMoves = solve(testerBoard).second;
    
    int ch, moveNo = 1;
    do {
        
        std::cout << "Win in " << minMoves << " moves!" << std::endl;
        testerBoard.printBoard();
        
        if (testerBoard.isSolved()) {
            std::cout << "Game over, you won!" << std::endl;
            return 0;
        }

        std::cout << "Press Q to quit and W, A, S, or D to move.\n";
        std::cout << "Move " << moveNo << ": ";
        
        ch = std::getchar();
        fflush(stdin); // handle 'RETURN' key or multiple keys

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
            default:
                continue;
        }
        moveNo++;
        std::system("clear");
    } while (ch != 'Q' && ch!='q');
  
    return 0;
}
