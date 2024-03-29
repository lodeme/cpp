#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	while (true)
	{
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, command))
			return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}
