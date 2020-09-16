#include "row.hpp"
#include <iostream>
#include <string>

/*
+---+---+---+---+
|   |   |   |   |

*/

std::string blankRow = "|   |   |   |   |";
std::string border = "+---+---+---+---+";

Row::Row() {
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
}

Row::Row(int a, int b, int c, int d) {
    first = a;
    second = b;
    third = c;
    fourth = d;
}

void Row::printRow() {
    std::string newRow = blankRow;

    newRow[2] = intToChar(this->first); 
    newRow[6] = intToChar(this->second); 
    newRow[10] = intToChar(this->third); 
    newRow[14] = intToChar(this->fourth); 

    std::cout << newRow << "\n";
}

void printBorder() {
    std::cout << border << "\n";
}

char intToChar(int tile) {
    char ret;
    switch(tile) {
        case 0:
            ret = ' ';
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            ret = tile + 48;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            ret = 65 + (tile - 10);
            break;
        default:
              ret = '*';
    }
    return ret;
}
