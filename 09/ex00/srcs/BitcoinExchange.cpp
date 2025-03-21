#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){ (void)src; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) { (void)src; return (*this); }
BitcoinExchange::~BitcoinExchange() {}

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
        if (!BitcoinExchange::dateIsValid(date))
        {
            cout << "Error: Date is not valid." << endl;
            exit(1);
            continue;
        }

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

bool BitcoinExchange::dateIsValid(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year, month, day;
    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) {
        return false;
    }
    
    if (year < 2009 || year > 2100)
        return false;
    if (month < 1 || month > 12)
        return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    
    return true;
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
        if (!BitcoinExchange::dateIsValid(date))
        {
            cout << "Error: Date is not valid." << endl;
            continue;
        }
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
        std::cout << "date = " << date << std::endl;
        
        float multiplicator = std::atof(value.c_str());
        if (multiplicator < 0 || multiplicator > 1000) {
            cout << "Error: number has to be between 0 and 1000." << endl;
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