#include "solver.hpp"
#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>


class comparator {
public:
    bool operator() (const std::pair<Board*, int> p1,
                    const std::pair<Board*, int> p2) {
        int hStar1 = p1.first->ManhattanDistance() + p1.second;
        int hStar2 = p2.first->ManhattanDistance() + p2.second;
        return hStar1 > hStar2;
    }
};

using heap = std::priority_queue<
    std::pair<Board*, int>,
    std::vector< std::pair<Board*, int> >,
    comparator>;

int aStar(heap q) {
    Board* b = q.top().first;
    int moves = q.top().second;
    q.pop();
    if (b->ManhattanDistance() == 0)
        return moves;
    else {
        Board* bprime = new Board(*b);
        bprime->up();
        if (! (*bprime == *b))
            q.push(std::make_pair(bprime, moves+1));
        
        bprime = new Board(*b);
        bprime->right();
        if (! (*bprime == *b))
            q.push(std::make_pair(bprime, moves+1));
        
        bprime = new Board(*b);
        bprime->down();
        if (! (*bprime == *b))
            q.push(std::make_pair(bprime, moves+1));
        
        bprime = new Board(*b);
        bprime->left();
        if (! (*bprime == *b))
            q.push(std::make_pair(bprime, moves+1));
        return aStar(q);
    }
}

int solve(Board b) {
    heap q;
    q.push(std::make_pair(new Board(b), 0));
    return aStar(q);
}


