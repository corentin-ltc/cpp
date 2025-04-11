#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

int main(int ac, char **av)
{
    std::map<std::string, float> btcPrices;

    if (ac != 2)
        BitcoinExchange::exit_msg("Please use the right syntax: \"./btc <filename>\".", "");

    try
    {
        btcPrices =  BitcoinExchange::getBtcPrice();
        BitcoinExchange::processInput(av, btcPrices);
    }
    catch(...)
    {
        ;
    }
    

    return 0;
}