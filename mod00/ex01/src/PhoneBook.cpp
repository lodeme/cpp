#include "PhoneBook.hpp"

int PhoneBook::getOldestContact() const
{
	int oldest = 0;
	for (int i = 0; i < 7; i++)
	{
		if (contacts[i].createdAt > contacts[i + 1].createdAt)
			oldest = i + 1;
	}
	return oldest;
}

void PhoneBook::addContact()
{
	int index = getOldestContact();
	contacts[index].setContact();
}

void PhoneBook::displayHeader() const
{
	std::cout
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|"
		<< std::endl
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::endl;
}

void PhoneBook::displayPhoneBook() const
{
	displayHeader();
	for (int i = 0; i < 8; i++)
		contacts[i].displayContactRow(i);
}

void PhoneBook::getSingleContact() const
{
	std::string input;
	int id;
	while (true)
	{
		std::cout << "Enter a contact number (0-7): ";
		if (!std::getline(std::cin, input))
			return ;
		std::stringstream ss(input);
		if (ss >> id && ss.eof() && id >= 0 && id <= 7)
			break ;
		std::cout << "Incorrect value: ";
	}
	contacts[id].displayFullContact();
}

void PhoneBook::searchContact() const
{
	displayPhoneBook();
	getSingleContact();
}
