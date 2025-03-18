#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        for (int i = 1; i < argc; ++i) {
            std::istringstream iss(argv[i]);
            int num;
            if (!(iss >> num) || num < 0) {
                throw std::invalid_argument("Invalid input");
            }
            vec.push_back(num);
            deq.push_back(num);
        }
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    std::cout << "Before: ";
    PmergeMe::printContainer(vec);
    
    clock_t startVec = clock();
    vec = PmergeMe::mergeInsertSort(vec);
    clock_t endVec = clock();
    
    clock_t startDeq = clock();
    deq = PmergeMe::mergeInsertSort(deq);
    clock_t endDeq = clock();
    
    std::cout << "After: ";
    PmergeMe::printContainer(vec);
    
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;
    
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
    
    return 0;
}
