#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp() {
    std::time_t currentTime = std::time(NULL);
    std::tm * const localTime = std::localtime(&currentTime);
    
    std::cout << "[" << 1900 + localTime->tm_year;
	if (localTime->tm_mon + 1 < 10)
		std::cout << "0" << localTime->tm_mon + 1;
	else
		std::cout << localTime->tm_mon + 1;
	if (localTime->tm_mday < 10)
		std::cout << "0" << localTime->tm_mday;
	else
		std::cout << localTime->tm_mday << "_";
	if (localTime->tm_hour < 10)
		std::cout << "0" << localTime->tm_hour;
	else
		std::cout << localTime->tm_hour;
	if (localTime->tm_min < 10)
		std::cout << "0" << localTime->tm_min;
	else
		std::cout << localTime->tm_min;
	if (localTime->tm_sec < 10)
		std::cout << "0" << localTime->tm_sec;
	else
		std::cout << localTime->tm_sec;
	std::cout << "] ";
}

Account::Account( void ) : 
_accountIndex(_nbAccounts), _amount(0),
_nbDeposits(0), _nbWithdrawals(0)
{
    //maj des infos globales sur les comptes
    _nbAccounts++;
    //affiche le statut du compte a la creation
    _displayTimestamp();
    std::cout << "index:" <<_nbAccounts << ";"
    << "amount:" <<_amount << ";"
    << "created" <<std::endl;
}

Account::Account( int initial_deposit ) : 
_accountIndex(_nbAccounts), _amount(initial_deposit),
_nbDeposits(0), _nbWithdrawals(0)
{
    //maj des infos globales sur les comptes
    _totalAmount += initial_deposit;
    _nbAccounts++;
    //affiche le statut du compte a la creation
    _displayTimestamp();
    std::cout << "index:" << _accountIndex  << ";"
    << "amount:" <<_amount << ";"
    << "created" <<std::endl;
}

Account::~Account( void )
{
    //maj des infos globales sur les comptes
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    //affiche le statut du compte a la destruction
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" <<_amount << ";"
    << "closed" << std::endl;
}

//affiche [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void    Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << 
    "index:" << _accountIndex << ";"
    "p_amount:" << p_amount << ";"
    "deposit:" << deposit << ";"
    "amount:" << _amount << ";"
    "nb_deposits:" << _nbDeposits
    << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << 
    "index:" << _accountIndex << ";"
    "amount:" << _amount << ";"
    "deposits:" << _nbDeposits << ";"
    "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << 
    "accounts:" << _nbAccounts << ";"
    "total:" << _totalAmount << ";"
    "deposits:" << _totalNbDeposits << ";"
    "withdrawals:" << _totalNbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const
{
    return(_amount);
}
    
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
