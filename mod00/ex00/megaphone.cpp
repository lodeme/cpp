#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg(argv[i]);
			for (unsigned int j = 0; j < arg.length(); j++)
				std::cout << (char)toupper(arg[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
