#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Expected use: ./harlFilter message" << std::endl;
		return EXIT_FAILURE;
	}
	Harl harl;
	harl.complain(argv[1]);
	return EXIT_SUCCESS;
}
