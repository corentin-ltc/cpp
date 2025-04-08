#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other){ (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }
PmergeMe::~PmergeMe() {}

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
//    std::cout << "left :";
//    printContainer(left);
//    std::cout << "right :";
//   printContainer(right);
    left = mergeInsertSort(left);
    right = mergeInsertSort(right);
    
    std::vector<int> merged = arr;
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }
    while (i < left.size())
        merged[k++] = left[i++];
    while (j < right.size())
        merged[k++] = right[j++];
    return merged;
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return arr;
    
    std::deque<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::deque<int> right(arr.begin() + arr.size() / 2, arr.end());
    
    left = mergeInsertSort(left);
    right = mergeInsertSort(right);
    
    std::deque<int> merged = arr;
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }
    while (i < left.size())
        merged[k++] = left[i++];
    while (j < right.size())
        merged[k++] = right[j++];
    return merged;
}