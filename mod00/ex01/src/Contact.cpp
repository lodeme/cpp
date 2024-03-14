#include "Contact.hpp"

bool Contact::isAscii(std::string str) const
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((unsigned char)(str[i]) > 127)
			return false;
	}
	return true;
}

void Contact::promptFieldValue(std::string prompt, std::string& field)
{
	while (true)
	{
		std::cout << "Enter " << prompt << ": ";
		if (!std::getline(std::cin, field))
			break;
		if (field.empty())
			std::cout << "Cannot be empty" << std::endl;
		else if (!isAscii(field))
			std::cout << "Only ASCII characters are allowed" << std::endl;
		else
			break;
	}
}

void Contact::setContact(void)
{
	promptFieldValue("First Name", firstName);
	promptFieldValue("Last Name", lastName);
	promptFieldValue("Nickname", nickname);
	promptFieldValue("Phone Number", phoneNumber);
	promptFieldValue("Darkest Secret", darkestSecret);
	createdAt = std::time(0);
	std::cout << "Contact added: " << lastName << ", " << firstName 
		<< std::endl;
}

std::string Contact::formatField(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void Contact::displayFullContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displayContactRow(int id) const
{
	std::cout
		<< std::setw(10) << id << "|"
		<< std::setw(10) << formatField(firstName) << "|"
		<< std::setw(10) << formatField(lastName) << "|"
		<< std::setw(10) << formatField(nickname) << "|"
		<< std::endl;
}
