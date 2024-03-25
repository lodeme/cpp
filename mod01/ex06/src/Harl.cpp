#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::formatMessage(std::string& prompt, void (Harl::*function)(void)) {
	std::cout << "[ " << prompt << " ]" << std::endl;
	(this->*function)();
	std::cout << std::endl;
}

void Harl::complain(std::string level) {
	std::string prompts[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && prompts[i].compare(level)) {
		i++;
	}

	switch(i) {
		case 0:
			formatMessage(prompts[0], &Harl::debug); // fall through
		case 1:
			formatMessage(prompts[1], &Harl::info); // fall through
		case 2:
			formatMessage(prompts[2], &Harl::warning); // fall through
		case 3:
			formatMessage(prompts[3], &Harl::error);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}