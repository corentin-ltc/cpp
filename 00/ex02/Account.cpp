#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void get_time() {
    char buffer[20];
    time_t timestamp;
    time(&timestamp);
    struct tm *datetime = gmtime(&timestamp);

    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", datetime);
    std::cout << buffer << ' ';
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    get_time();
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account() {
    _nbAccounts--;
    _totalAmount -= _amount;
    get_time();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    get_time();
    std::cout << "accounts:" << _nbAccounts << ";total:" 
              << _totalAmount << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    get_time();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit 
              << ";deposit:" << deposit << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    get_time();
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal 
                  << ";withdrawal:" << withdrawal << ";amount:" << _amount 
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
}

void Account::displayStatus() const {
    get_time();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}
