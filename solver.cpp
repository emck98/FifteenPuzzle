#include "solver.hpp"
#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>


class h {
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
    h>;

int aStar(heap q) {
    if (q.empty()) return -1;
    else std::cout << q.size() << std::endl;
    Board* b = q.top().first;
    int moves = q.top().second;
    q.pop();
    
    Board* bprime = new Board(*b);
    bprime->up();
    if (bprime->ManhattanDistance() == 0)
        return moves + 1;
    else if (! (*bprime == *b))
        q.push(std::make_pair(bprime, moves+1));
    
    bprime = new Board(*b);
    bprime->right();
    if (bprime->ManhattanDistance() == 0)
        return moves + 1;
    else if (! (*bprime == *b))
        q.push(std::make_pair(bprime, moves+1));
    
    bprime = new Board(*b);
    bprime->down();
    if (bprime->ManhattanDistance() == 0)
        return moves + 1;
    else if (! (*bprime == *b))
        q.push(std::make_pair(bprime, moves+1));
    
    bprime = new Board(*b);
    bprime->left();
    if (bprime->ManhattanDistance() == 0)
        return moves + 1;
    else if (! (*bprime == *b))
        q.push(std::make_pair(bprime, moves+1));
    
    return aStar(q);
}

int solve(Board b) {
    if (b.ManhattanDistance() == 0) return 0;
    else {
        heap q;
        q.push(std::make_pair(new Board(b), 0));
        return aStar(q);
    }
}


