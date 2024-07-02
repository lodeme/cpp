#include <Bureaucrat.hpp>
#include <iostream>

int main(void) {
  /* Grade too high */
	{
		try
		{
			Bureaucrat jean("jean", 0);
			std::cout << jean << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n";

  /* Grade too low */
	{
		try {
			Bureaucrat jeanne("jeanne", 151);
			std::cout << jeanne << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n";
	
  /* Too much incrementing */
	{	
		try 
		{
			Bureaucrat bur1("bur1", 3);
			std::cout << bur1 << std::endl;
			bur1.incrementGrade();
			std::cout << bur1 << std::endl;
			bur1.incrementGrade();
			std::cout << bur1 << std::endl;
			bur1.incrementGrade();
			std::cout << bur1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n";

  /* Too much decrementing */
	{
		try
		{
			Bureaucrat bur2("bur2", 149);
			std::cout << bur2 << std::endl;
			bur2.decrementGrade();
			std::cout << bur2 << std::endl;
			bur2.decrementGrade();
			std::cout << bur2 << std::endl;
			bur2.decrementGrade();
			std::cout << bur2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
