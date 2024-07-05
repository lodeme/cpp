#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    // canonical form
    AForm();
    ~AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm& operator=(AForm& other);
    AForm(const AForm& other);

    // getters and setters
    const std::string& getName();
    bool getIsSigned();
    int getGradeToSign();
    int getGradeToExecute();

    // exceptions
    class gradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class gradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };

    // Other member funtions
    virtual void beSigned(Bureaucrat& b) = 0;
};

std::ostream& operator<<(std::ostream& str, AForm& form);

#endif
