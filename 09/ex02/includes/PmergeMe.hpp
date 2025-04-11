#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        static void printContainer(const std::vector<int>& container);
        static void printContainer(const std::deque<int>& container);
        static std::vector<int> mergeInsertSort(std::vector<int>& arr);
        static std::deque<int> mergeInsertSort(std::deque<int>& arr);
        bool isDigitsOnly(const std::string& str);
        int parseInput(const std::string& str);
        std::vector<int> parseArgs(int argc, char **argv);



};


