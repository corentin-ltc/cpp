#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;



int main(int ac, char **av)
{
    std::map<std::string, float> btcPrices;

    if (ac != 2)
        BitcoinExchange::exit_msg("Please use the right syntax: \"./btc <filename>\".", "");
    btcPrices =  BitcoinExchange::getBtcPrice();
    BitcoinExchange::processInput(av, btcPrices);

    // std::string line , date , value ;
    // std::map<std::string, float> rates;

    // if (ac != 2)
    //     exit_msg("Please use the right syntax: \"./btc <filename>\".");
    // // parsing (ouverture du fichier, verif dates valides, valeur valide)
    
    // std::ifstream ratesFile;
    // ratesFile.open(av[1]);
    // if (!ratesFile.is_open())
    //     exit_msg("ERROR: Couldn't open ", av[1]);
    // getline(ratesFile, line);
    // while (getline(ratesFile, line))
    // {
    //     if (line.empty())
    //         continue;
    //     size_t separatorPos = line.find('|');
    //     if (separatorPos == std::string::npos)
    //     {
    //         cout << "Error: Bad input => " << line << endl;
    //         continue;
    //     }
    //     date = line.substr(0, separatorPos);
    //     value = line.substr(separatorPos + 1);
    //     date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
    //     value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
    //     float multiplicator = std::atof(value.c_str());
    //     if (multiplicator <= 0) {
    //         cout << "Error: Invalid value => " << value << endl;
    //         continue;
    //     }
    //     rates[date] = multiplicator;
    //     cout << date << " => " << multiplicator << endl;
    // }
    // ratesFile.close();


    return 0;
}