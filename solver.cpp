#include "solver.hpp"

#include <vector>
#include <map>
#include <array>
#include <iostream>

#define FOUND -1
#define MAX_DEPTH 10000

typedef void (Board::*BoardMemFn)(void);
BoardMemFn succFn[] = {
                    &Board::up, &Board::right,
                    &Board::down, &Board::left
};

int h(Board* b) {
    return b->ManhattanDistance() + 2*b->boardInversions();
}

bool member(std::vector<Board*>* v, Board* b) {
    for (auto iter = v->rbegin(); iter != v->rend(); iter++)
        if (**iter == *b) return true;
    return false;
}

std::array<BoardMemFn, 4> generate(Board* parent) {
    std::multimap<int, BoardMemFn> children;
    for (int i = 0; i < 4; i++) {
        Board* bpStar = new Board(*parent);
        ((bpStar)->*(succFn[i]))();
        children.insert(std::make_pair(h(bpStar), succFn[i]));
        delete bpStar;
    }
    std::array<BoardMemFn, 4> orderedFns;
    auto iter = children.begin();
    for (int i = 0; i < 4; i++) {
        orderedFns[i] = iter->second;
        iter++;
    }
    return orderedFns;
}

int IDAStar(std::pair<std::vector<Board*>, int>& p, int bound) {
    std::vector<Board*>* path = &p.first;
    Board* bp = path->back();
    int f = h(bp) + p.second;
    std::cout << "f: " << bound << std::endl;
    if (f > bound) return f;
    else if (bp->isSolved()) return FOUND;
    else {
        int min = INT_MAX;
        std::array<BoardMemFn, 4> fns = generate(bp);
        p.second++;
        for(auto fStar = fns.begin(); fStar != fns.end(); fStar++) {
            Board* bpStar = new Board(*bp);
            ((bpStar)->*(*fStar))();
            if (! member(path, bpStar)) {
                path->push_back(bpStar);
                int t = IDAStar(p, bound);
                if (t == FOUND) return FOUND;
                min = std::min(min, t);
                path->pop_back();
            }
            else std::cout << "repeat" << std::endl;
            delete bpStar;
        }
        return min;
    }
}

std::pair<std::vector<Board*>, int> solve(Board b) {
    int bound = h(&b);
    std::cout << "Init bd: " << bound << std::endl;
    Board* bp = new Board(b);
    std::vector<Board*> path;
    path.push_back(bp);
    std::pair<std::vector<Board*>, int> p;
    while (bound != FOUND && bound < MAX_DEPTH) {
        p = std::make_pair(path, 0);
        bound = IDAStar(p, bound);
        // std::cout << bound << std::endl;
    }
    p.first.back()->printBoard();
    return p;
}
