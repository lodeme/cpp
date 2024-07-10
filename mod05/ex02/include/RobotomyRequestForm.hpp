#ifndef RR_FORM_HPP
#define RR_FORM_HPP

#include <string>
#include <AForm.hpp>

class RobotomyRequestForm : public AForm {
  private:
    const std::string _target;

  public:
    // canonical form
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm& operator=(RobotomyRequestForm& other);
    RobotomyRequestForm(const RobotomyRequestForm& other);

    // other
    void execute(const Bureaucrat& bureaucrat) const;
    bool flipCoin() const;
};

#endif
