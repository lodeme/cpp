#include <exception>
#include <ostream>
#include <string>

class Form {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    // canonical form
    Form();
    ~Form();
    Form(std::string& name, int gradeToSign, int gradeToExecute);
    Form& operator=(Form& other);

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
};

std::ostream& operator<<(std::ostream& str, Form& form);
