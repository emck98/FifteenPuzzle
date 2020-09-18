#include "solver.hpp"
#include <queue>
#include <vector>
#include <iostream>



bool operator< (const std::pair<Board*, int> p1,
                const std::pair<Board*, int> p2) {
    int hStar1 = p1.first->ManhattanDistance() + p1.second;
    int hStar2 = p1.first->ManhattanDistance() + p1.second;
    return hStar1 < hStar2;
}

int aStar(std::priority_queue< std::pair<Board*, int> > q) {
    Board* b = q.top().first;
    int moves = q.top().second;
    if (b->ManhattanDistance() == 0)
        return moves;
    else {
        b->up();
        q.push(std::make_pair(new Board(*b), moves+1));
        b->down();
        b->right();
        q.push(std::make_pair(new Board(*b), moves+1));
        b->left();
        b->down();
        q.push(std::make_pair(new Board(*b), moves+1));
        b->up();
        b->left();
        q.push(std::make_pair(new Board(*b), moves+1));
        q.pop();
        return aStar(q);
    }
}

int solve(Board b) {
    std::priority_queue< std::pair<Board*, int> > q;
    q.push(std::make_pair(new Board(b), 0));
    return aStar(q);
}


