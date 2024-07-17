#include <Span.hpp>
#include <iostream>

int	main( void ) {
	{
		std::cout << "\033[1;32mTest 1\033[0m: eval sheet test" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 1\033[0m: span of size 4, filled manually" << std::endl;
		Span	span = Span(4);
		try {
			span.addNumber(42);
			span.addNumber(24);
			span.addNumber(205);
			span.addNumber(485);
			span.addNumber(1);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
		{
		std::cout << std::endl << "\033[1;32mTest 2\033[0m: span of size 10, filled randomly" << std::endl;
		Span	span = Span(10);
		span.fillAll();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 3\033[0m: span of size 10000, filled randomly" << std::endl;
		Span	span = Span(10000);
		span.fillAll();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 3\033[0m: span of size 1000000, filled randomly" << std::endl;
		Span	span = Span(1000000);
		span.fillAll();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 4\033[0m: span too short" << std::endl;
		Span	span = Span(2);
		span.addNumber(1);
		try {
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;32mTest 5\033[0m: span of size 2" << std::endl;
		Span	span = Span(2);
		span.addNumber(1);
		span.addNumber(-1);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 6\033[0m: span of size 2, same numbers" << std::endl;
		Span	span = Span(2);
		span.addNumber(42);
		span.addNumber(42);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
}

