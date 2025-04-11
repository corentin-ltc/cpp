#include "PmergeMe.hpp"
#include <cctype>
#include <limits>
#include <string>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other){ (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }
PmergeMe::~PmergeMe() {}

bool PmergeMe::isDigitsOnly(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t startPos = 0;
    
    if (str[0] == '+') {
        startPos = 1;
        if (str.length() == 1)
            return false;
    }
    for (size_t i = startPos; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

int PmergeMe::parseInput(const std::string& str) {
    if (!isDigitsOnly(str)) {
        throw std::invalid_argument("Error: Input contains non-digit characters.");
    }
    size_t startPos = 0;
    if (str[0] == '+') {
        startPos = 1;
    }
    if (str.length() - startPos > 10) { 
        throw std::overflow_error("Error: Input value exceeds integer maximum.");
    }
    if (str.length() - startPos == 10) { 
        if (str.compare(startPos, std::string::npos, "2147483647") > 0) {
            throw std::overflow_error("Error: Input value exceeds integer maximum.");
        }
    }
    std::istringstream iss(str);
    int value;
    iss >> value;
    
    if (iss.fail()) {
        throw std::invalid_argument("Error: Invalid number format.");
    }
    return value;
}

std::vector<int> PmergeMe::parseArgs(int argc, char **argv) {
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        int value = parseInput(argv[i]);
        numbers.push_back(value);
    }
    return numbers;
}

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
    left = mergeInsertSort(left);
    right = mergeInsertSort(right);
    std::vector<int> merged = arr;
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
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
    while (i < left.size() && j < right.size()) {
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