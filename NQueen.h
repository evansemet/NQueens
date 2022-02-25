//
// Created by Evan Semet on 2/25/22.
//

#ifndef NQUEEN_NQUEEN_H
#define NQUEEN_NQUEEN_H
#include <vector>
#include <iostream>

class NQ {
private:
    size_t N;
    std::vector<std::vector<size_t>> board;

public:

    NQ(size_t n);

    size_t n();

    void print();

    bool valid(size_t row, size_t col);

    bool solve(size_t place);

};

#endif //NQUEEN_NQUEEN_H
