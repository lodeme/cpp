#include "Account.hpp"
#include <iostream>
#include <cstdio>
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
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer;
}

