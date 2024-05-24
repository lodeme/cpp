#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t currentTime = time(0);
	struct tm *localTime = localtime(&currentTime);
	char buffer[20];
	strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << buffer << std::flush;
}

Account::Account(int deposit)
{
	_accountIndex = _nbAccounts;
  _amount = 0;
	_amount += deposit;
	_totalAmount+= deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:"
		<< std::flush;
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	std::cout
		<< withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}
