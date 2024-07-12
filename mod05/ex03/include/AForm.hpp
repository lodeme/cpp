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
    virtual ~AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm& operator=(AForm& other);
    AForm(const AForm& other);

    // getters and setters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // exceptions
    class gradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class gradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class formNotSignedException: public std::exception {
      public:
        virtual const char* what() const throw();
    };

    // Other member funtions
    virtual void beSigned(Bureaucrat& b);
    virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& str, AForm& form);

#endif
