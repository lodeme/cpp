#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    // canonical form
    Bureaucrat(void);
    ~Bureaucrat(void);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
  
    // getters and setters
    const std::string& getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
    
    // Exceptions handling
    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
    
    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what(void) const throw();
    };

  // Other functions
  void signForm(AForm& f);
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &b);

#endif
