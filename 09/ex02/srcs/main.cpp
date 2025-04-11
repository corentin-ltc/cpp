#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

int main(int argc, char* argv[])
{
    PmergeMe sorter;
    std::vector<int> vec;
    std::deque<int> deq;

    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        vec = sorter.parseArgs(argc, argv);
        
        for (size_t i = 0; i < vec.size(); ++i) {
            deq.push_back(vec[i]);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    sorter.printContainer(vec);

    clock_t startVec = clock();
    vec = sorter.mergeInsertSort(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    deq = sorter.mergeInsertSort(deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    sorter.printContainer(vec);

    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;

    return 0;
}