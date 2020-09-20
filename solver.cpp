#include "solver.hpp"
#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>


class h {
public:
    bool operator() (const std::pair<Board*, int>* p1,
                    const std::pair<Board*, int>* p2) {
        int hStar1 = p1->first->ManhattanDistance() + p1->second;
        int hStar2 = p2->first->ManhattanDistance() + p2->second;
        return hStar1 > hStar2;
    }
};

using heap = std::priority_queue<
    std::pair<Board*, int>*,
    std::vector< std::pair<Board*, int>* >,
    h>;

typedef void (Board::*BoardMemFn)(void);
BoardMemFn f[] = {
                    &Board::up, &Board::right,
                    &Board::down, &Board::left
};


int aStar(heap& q) {
    //std::cout << "Done" << std::endl;
    
    //std::cout << "Grabbing...";
    if (q.empty()) return -1;
    //else std::cout << q.size() << std::endl;
    const std::pair<Board*, int>* p = q.top();
    q.pop();
    Board* b = p->first;
    int moves = p->second;

    //std::cout << "Done" << std::endl;

    for (int i=0; i < 4; i++) {
        Board* bprime = new Board(*b);
        ((bprime)->*(f[i]))();
        if (bprime->ManhattanDistance() == 0)
            return moves + 1;
        else if (! (*bprime == *b)
                 && b->ManhattanDistance() > bprime->ManhattanDistance())
        q.push(new std::pair<Board*, int>(bprime, moves+1));
        ((bprime)->*(f[(i+2) % 4]))();
    }
    
    //std::cout << "Deleting...";
    delete p;
    //std::cout << "Done" << std::endl;
    
    //std::cout << "Calling Child...";
    return aStar(q);
}

int solve(Board b) {
    if (b.ManhattanDistance() == 0) return 0;
    else {
        heap q;
        q.push(new std::pair<Board*, int>(new Board(b), 0));
        return aStar(q);
    }
}
