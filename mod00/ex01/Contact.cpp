#include <iostream>
#include "Contact.hpp"

void Contact::setContact(void)
{
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret";
	std::getline(std::cin, darkestSecret);
	createdAt = std::time(0);
}

void Contact::displayContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displayHeader() const
{
	std::cout
		<< "First Name | Last Name | Nickname | Phone Number | Darkest Secret"
		<< std::endl;
}
