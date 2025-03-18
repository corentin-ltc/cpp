#include "PmergeMe.hpp"

void PmergeMe::printContainer(const std::vector<int>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int>& arr) {
    
    if (arr.size() <= 1)
        return arr;
    
    std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());
    std::cout << "left :";
    printContainer(left);
    std::cout << "right :";
    printContainer(right);
    left = mergeInsertSort(left);
    right = mergeInsertSort(right);
    
    std::vector<int> merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
    std::cout << "merged :";
    printContainer(merged);
    return merged;
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int>& arr) {
    if (arr.size() <= 1) return arr;
    
    std::deque<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::deque<int> right(arr.begin() + arr.size() / 2, arr.end());
    
    left = mergeInsertSort(left);
    right = mergeInsertSort(right);
    
    std::deque<int> merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
    return merged;
}