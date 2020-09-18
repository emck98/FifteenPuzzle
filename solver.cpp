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

int aStar(heap q, std::unordered_set<Board> h) {
    Board* b = q.top().first;
    int moves = q.top().second;
    q.pop();
    std::cout << moves << std::endl;
    if (b->ManhattanDistance() == 0)
        return moves;
    else {
        b->up();
        if (h.find(*b) == h.end()) {
            h.insert(*b);
            q.push(std::make_pair(new Board(*b), moves+1));
        }
        b->down();
        b->right();
        if (h.find(*b) == h.end()) {
            h.insert(*b);
            q.push(std::make_pair(new Board(*b), moves+1));
        }
        b->left();
        b->down();
        if (h.find(*b) == h.end()) {
            h.insert(*b);
            q.push(std::make_pair(new Board(*b), moves+1));
        }
        b->up();
        b->left();
        if (h.find(*b) == h.end()) {
            h.insert(*b);
            q.push(std::make_pair(new Board(*b), moves+1));
        }
        return aStar(q, h);
    }
}

int solve(Board b) {
    heap q;
    q.push(std::make_pair(new Board(b), 0));
    std::unordered_set<Board> h;
    h.insert(b);
    return aStar(q, h);
}


