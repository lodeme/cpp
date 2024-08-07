#include <string>

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
    Bureaucrat(Bureaucrat& other);
  
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
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &b);
