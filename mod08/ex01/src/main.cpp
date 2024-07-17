#include <Span.hpp>
#include <iostream>

int	main( void ) {

	{
		std::cout << "Test 1" << std::endl;
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "Test 2" << std::endl;
		Span	span = Span(4);
		try {
			span.addNumber(43242);
			span.addNumber(244324);
			span.addNumber(2054324);
			span.addNumber(484555);
			span.addNumber(13);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "Test 3" << std::endl;
		Span	span = Span(100);
		span.fillAll();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "Test 4" << std::endl;
		Span	span = Span(10000000);
		span.fillAll();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "Test 5" << std::endl;
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
		std::cout << std::endl << "Test 6" << std::endl;
		Span	span = Span(2);
		span.addNumber(1);
		span.addNumber(-1);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "Test 7" << std::endl;
		Span	span = Span(2);
		span.addNumber(2);
		span.addNumber(2);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
}

