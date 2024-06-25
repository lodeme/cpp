#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat(void);
    ~Bureaucrat(void);
    Bureaucrat(std::string& name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
};
