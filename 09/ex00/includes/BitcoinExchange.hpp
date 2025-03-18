#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <fstream>

class BitcoinExchange
{
    private:
    static std::map<std::string, float> rates;
    public:
        BitcoinExchange();
	    BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();

        static std::map<std::string, float> getBtcPrice();
        static void processInput(char **av, std::map<std::string, float> btcPrices);
        static void exit_msg(std::string msg, std::string msg2);
};


