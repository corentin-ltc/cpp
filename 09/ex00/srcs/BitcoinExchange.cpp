#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

void BitcoinExchange::exit_msg(std::string msg, std::string msg2 = "")
{
    cout << msg << msg2 << endl;
    exit(1);
}

std::map<std::string, float> BitcoinExchange::getBtcPrice()
{
    std::string line , date , price, value ;
    std::ifstream BtcFile;
    std::map<std::string, float> btcPrices;

    BtcFile.open("data.csv");
    if (!BtcFile.is_open())
        exit_msg("ERROR: Couldn't open ", "data.csv");
    getline(BtcFile, line);
    while (getline(BtcFile, line))
    {
        if (line.empty())
            continue;
        size_t separatorPos = line.find(',');
        if (separatorPos == std::string::npos)
        {
            cout << "Error: data.csv has been corrupted." << line << endl;
            exit(1);
            continue;
        }
        date = line.substr(0, separatorPos);
        value = line.substr(separatorPos + 1);
        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
        float price = std::atof(value.c_str());
        if (price < 0) {
            cout << "Error: Price can't be negative." << endl;
            exit(1);
            continue;
        }
        btcPrices[date] = price;
    }
    BtcFile.close();
    return btcPrices;
}

void BitcoinExchange::processInput(char **av, std::map<std::string, float> btcPrices)
{
    std::string line , date , value ;
    std::map<std::string, float> rates;

    std::ifstream ratesFile;
    ratesFile.open(av[1]);
    if (!ratesFile.is_open())
        exit_msg("ERROR: Couldn't open ", av[1]);
    getline(ratesFile, line);
    while (getline(ratesFile, line))
    {
        if (line.empty())
            continue;
        size_t separatorPos = line.find('|');
        if (separatorPos == std::string::npos)
        {
            cout << "Error: Bad input => " << line << endl;
            continue;
        }
        date = line.substr(0, separatorPos);
        value = line.substr(separatorPos + 1);
        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
        float multiplicator = std::atof(value.c_str());
        if (multiplicator <= 0) {
            cout << "Error: Not a positive number." << endl;
            continue;
        }
        if (multiplicator > 2147483647.0) {
            cout << "Error: too large number." << endl;
            continue;
        }
        std::map<std::string, float>::iterator closest = btcPrices.end();
        for (std::map<std::string, float>::iterator it = btcPrices.begin() ; it != btcPrices.end(); it++)
        {
            if (it->first > date)
                break;
            closest = it;
        }
        if (closest == btcPrices.end())
        {
            cout << "No valid BTC price found for or before date: (Please check if the date is valid : YYYY-MM-DD): " << date << endl;
            continue;
        }
        float result = multiplicator * closest->second;
        cout << date << " => " << multiplicator << " = " << result << endl;
    }
    ratesFile.close();
}