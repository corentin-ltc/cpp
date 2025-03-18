#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        PmergeMe();
    public:
        static void printContainer(const std::vector<int>& container);
        static void printContainer(const std::deque<int>& container);
        static std::vector<int> mergeInsertSort(std::vector<int>& arr);
        static std::deque<int> mergeInsertSort(std::deque<int>& arr);
};


