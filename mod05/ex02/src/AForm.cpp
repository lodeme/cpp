#include <BureaucratForm.hpp>

AForm::AForm():
  _name("Default"), _signed(false), _gradeToSign(75), _gradeToExecute(75) {
}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
  _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw gradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw gradeTooLowException();
}

AForm& AForm::operator=(AForm& other) {
  if (this != &other)
    this->_signed = other._signed;
  return *this;
}

AForm::AForm(const AForm& other)
  : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

const std::string& AForm::getName() const {
  return _name;
}

bool AForm::getIsSigned() {
  return _signed;
}

int AForm::getGradeToSign() {
  return _gradeToSign;
}

int AForm::getGradeToExecute() {
  return _gradeToExecute;
}

const char* AForm::gradeTooHighException::what() const throw() {
  return "Grade is too high too proceed";
}

const char* AForm::gradeTooLowException::what() const throw() {
  return "Grade is too low to proceed";
}

const char* AForm::formNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream& operator<<(std::ostream& str, AForm& form) {
  return str  << "Form " << form.getName()
              << ", is signed: " << form.getIsSigned()
              << ". Requires grades of " << form.getGradeToSign()
              << " to sign and " << form.getGradeToExecute()
              << " to execute";
}

void AForm::beSigned(Bureaucrat& b) {
  if (b.getGrade() <= _gradeToSign)
    _signed = true;
  else
    throw gradeTooLowException();
}
