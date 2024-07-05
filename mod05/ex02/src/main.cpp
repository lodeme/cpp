#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <iostream>

int main( void )
{

    try {
        Bureaucrat john("John",11);
        AForm form("B24", 10, 10);
        john.signForm(form);
        std::cout << form << std::endl;
        Bureaucrat jane("Jane",10);
        jane.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
