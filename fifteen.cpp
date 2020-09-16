#include "hello.hpp"
#include "board.hpp"
#include "row.hpp"

#include <stdio.h>
#include <iostream>



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
    std::cout << "Press Q to quit\n";
    do  {

        testerBoard.printBoard();

        if (testerBoard.isSolved()) {
            std::cout << "Game over, you won! \n";
            return 0;
        }


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



    } while (ch != 'Q' && ch!='q');
    // int c = 0;
    // while(1) {
    //     c = 0;

    //     switch((c=getch())) {
    //     case KEY_UP:
    //         cout << endl << "Up" << endl;//key up
    //         break;
    //     case KEY_DOWN:
    //         cout << endl << "Down" << endl;   // key down
    //         break;
    //     case KEY_LEFT:
    //         cout << endl << "Left" << endl;  // key left
    //         break;
    //     case KEY_RIGHT:
    //         cout << endl << "Right" << endl;  // key right
    //         break;
    //     default:
    //         cout << endl << "null" << endl;  // not arrow
    //         break;
    //     }

    // }
    
    // Board testBoard;
    //testBoard.printBoard();
    // Row testRow1(1, 2, 3, 4);
    // testRow1.printRow();
    // printBorder();


    // Row testRow2(5, 6, 7, 8);
    // testRow2.printRow();
    // printBorder();

    // Row testRow3(9, 10, 11, 12);
    // testRow3.printRow();
    // printBorder();

    // Row testRow4(13, 14, 15, 0);
    // testRow4.printRow();
    // printBorder();

    //int tester [16] = {10, 2, 13, 4, 0, 6, 7, 8, 9, 11, 1, 12, 3, 14, 15, 2};

    // int tester [16] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 0, 10, 11, 12, 13, 14, 15};
    // int tester2 [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15};
    // int tester3 [16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // Board otherBoard(tester2);

    // otherBoard.printBoard();

    // int x = blankRow(tester);

    // int y = boardInversions(tester);

    // bool k = isValid15(tester2);

    // std::cout << k << "\n";

    // int tester [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 11};

    // int sol [16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    // Board testerBoard(tester);
    // testerBoard.correct();

    // Board solBoard(sol);
    // solBoard.correct();

    // bool a = solBoard.isSolved();
    // bool b = testerBoard.isSolved();

    // std::cout << a << " for sol board\n";
    // std::cout << b << " for test board\n";


    // testerBoard.printBoard();

    // testerBoard.right();

    // testerBoard.down();
    // testerBoard.down();

    // testerBoard.left();

    // testerBoard.down();
    // testerBoard.down();
    // testerBoard.up();

    // testerBoard.printBoard();

    // testerBoard.up();
    // testerBoard.correct();
    // testerBoard.printBoard();

    
    return 0;
}