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
  
    // getters and setters
    const std::string& getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
};
