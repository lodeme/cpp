#include "Contact.hpp"

void Contact::setContact(void)
{
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	createdAt = std::time(0);
	std::cout << "Contact added: " << lastName << ", " << firstName 
		<< std::endl;
}

void Contact::displayFullContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displayContactRow() const
{
	std::cout
		<< std::setw(10) << firstName << "|"
		<< std::setw(10) << lastName << "|"
		<< std::setw(10) << nickname << "|"
		<< std::setw(10) << phoneNumber << "|"
		<< std::setw(10) << darkestSecret
		<< std::endl;
}
