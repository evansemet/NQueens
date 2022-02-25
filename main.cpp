#include <iostream>
#include "NQueen.h"
#include <chrono>

int main() {
    NQ demonstration(10);
    demonstration.print();
    auto start = std::chrono::high_resolution_clock::now();
    demonstration.solve(demonstration.n());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nSolution found in " << (float) duration.count() / 1000000 << " seconds.\n";
    return 0;
}
