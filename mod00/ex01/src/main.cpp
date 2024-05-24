#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook pb;
	while (true)
	{
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, command))
			return (1);
		else if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command";
		std::cout << std::endl;
	}
	return (0);
}
