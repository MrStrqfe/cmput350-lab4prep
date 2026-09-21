#include <cstddef>  // size_t
#include <random>
#include <cstdint>
#include <list>
#include <iostream>
#include <vector>


#include "timer.h"
constexpr size_t SIZE = 16000000;

// Author: Jensen Lee

int main() {
    // test here...
    // Initialization
    Timer timer;
    std::mt19937_64 rng(0);

    // list insertion
    rng.seed(0);
    std::list<uint64_t> list;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        list.push_back(rng());
    }
    uint64_t timeListInsert = timer.click<Timer::Micros>();
    std::cout << "time was " << timeListInsert << "\n";

    // vector with no reserve
    rng.seed(0);
    std::vector<uint64_t> vecNoReserve;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vecNoReserve.push_back(rng());
    }
    uint64_t timeVecNoRes = timer.click<Timer::Micros>();
    std::cout << "time for vector no reserve is " << timeVecNoRes << "\n";

    // vector with reserve
    rng.seed(0);
    std::vector<uint64_t> vecReserve;
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        vecReserve.push_back(rng());
    }
    uint64_t timeVecRes = timer.click<Timer::Micros>();
    std::cout << "time for vector with reserve is " << timeVecRes << "\n";

    // list summation
    uint64_t listSum = 0;
    timer.restart();
    for (const auto val : list) {
        listSum += val;
    }
    uint64_t timeListSum = timer.click<Timer::Micros>();
    std::cout << "The Sum is " << listSum << " and the time was " << timeListSum << "\n";

    // vector summation
    uint64_t vecSum = 0;
    timer.restart();
    for (const auto val : list) {
        vecSum += val;
    }
    uint64_t vecListSum = timer.click<Timer::Micros>();
    std::cout << "The Sum is " << vecSum << " and the time was " << vecListSum << "\n";
    return 0;
}
