#include "NQueen.h"


NQ::NQ(size_t n) : N(n), board(N, std::vector<size_t>(N, 0)) {}


void NQ::print() {
    std::cout << "\n";
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << " " << board[i][j];
            if (j == board[i].size() - 1) std::cout << "\n";
        }
    }
    std::cout << "\n" << " ";
    for (size_t k = 0; k < N * 2 - 1; ++k) std::cout << "-";
    std::cout << "\n";
}

size_t NQ::n() {
    return N;
}


bool NQ::valid(size_t row, size_t col) {
    //check row and col
    for (size_t i = 0; i < board.size(); ++i) if (board[i][col]) return false;
    for (size_t j = 0; j < board.size(); ++j) if (board[row][j]) return false;

    //check left up diagonal
    size_t LUrow = row, LUcol = col;
    while (LUrow >= 0 && LUrow < board.size() && LUcol >= 0 && LUcol < board[0].size()) {
        if (board[LUrow][LUcol]) return false;
        --LUrow;
        --LUcol;
    }
    //check left down diagonal
    size_t LDrow = row, LDcol = col;
    while (LDrow >= 0 && LDrow < board.size() && LDcol >= 0 && LDcol < board[0].size()) {
        if (board[LDrow][LDcol]) return false;
        ++LDrow;
        --LDcol;
    }
    return true;
}


bool NQ::solve(size_t place) {
    if (!place) {
        print();
        return true;
    }

    size_t col = N - place;
    for (size_t row = 0; row < board.size(); ++row) {
        if (valid(row, col)) {
            board[row][col] = 1;
            solve(place - 1);
        }
        board[row][col] = 0;
    }
}

