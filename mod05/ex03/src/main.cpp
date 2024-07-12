#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <Intern.hpp>

int main( void )
{
  Intern  jules;
  AForm*   f1;
  AForm*   f2;

  f1 = jules.makeForm("robotomy", "Robo");
  f2 = jules.makeForm("robotomy request", "Robo");
  delete f1;
  delete f2;
  return 0;
}

