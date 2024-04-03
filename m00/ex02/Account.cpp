#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

void Account::_displayTimestamp() {
    std::time_t currentTime = std::time(nullptr); //nb de secondes ecoulees depuis 1970
    std::tm* localTime = std::localtime(&currentTime); //retourne timestamp 

    // Utilisation de std::put_time pour formater la sortie du timestamp
    std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "] ";
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
    std::cout << "index:" <<_nbAccounts << ";"
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
    std::cout << "index:" <<_nbAccounts << ";"
    << "amount:" <<_amount << ";"
    << "closed" <<std::endl;
}

//affiche [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void    Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << 
    "index:" << _accountIndex << ";"
    "p_amount:" << p_amount << ";"
    "amount:" << _amount << ";"
    "deposit:" << deposit << ";"
    "nb_deposits:" << _totalNbDeposits
    << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;
    bool    status = true;

    _displayTimestamp();
    std::cout << 
    "index:" << _accountIndex << ";"
    "p_amount:" << p_amount << ";"; 
    if (withdrawal < _amount)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << 
        "withdrawal:" << withdrawal << ";"
        "amount:" << _amount << ";"
        "nb_withdrawals:" << _totalNbWithdrawals;
        return (true);
    }
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
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
