#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _target;

  public:
    // canonical form
    AForm();
    ~AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm& operator=(AForm& other);
};

#endif
