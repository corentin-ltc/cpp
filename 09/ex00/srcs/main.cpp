#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;

void exit_msg(std::string msg, std::string msg2 = "")
{
    cout << msg << msg2 << endl;
    exit(1);
}

int main(int ac, char **av)
{
    std::string line , date , price, value ;
    std::map<std::string, float> rates;

    if (ac != 2)
        exit_msg("Please use the right syntax: \"./btc <filename>\".");
    // parsing (ouverture du fichier, verif dates valides, valeur valide)
    
    std::ifstream iFile;
    iFile.open(av[1]);
    if (!iFile.is_open())
        exit_msg("ERROR: Couldn't open ", av[1]);
    getline(iFile, line);
    while (getline(iFile, line))
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
        float numericValue = std::atof(value.c_str());
        if (numericValue <= 0) {
            cout << "Error: Invalid value => " << value << endl;
            continue;
        }
        rates[date] = numericValue;
        cout << date << " => " << numericValue << endl;
    }
    iFile.close();


    return 0;
}