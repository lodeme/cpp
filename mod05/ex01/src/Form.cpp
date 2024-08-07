#include <BureaucratForm.hpp>

Form::Form():
  _name("Default"), _signed(false), _gradeToSign(75), _gradeToExecute(75) {
}

Form::~Form() {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
  _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw gradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw gradeTooLowException();
}

Form& Form::operator=(Form& other) {
  if (this != &other)
    this->_signed = other._signed;
  return *this;
}

Form::Form(const Form&other) 
  : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

const std::string& Form::getName() {
  return _name;
}

bool Form::getIsSigned() {
  return _signed;
}

int Form::getGradeToSign() {
  return _gradeToSign;
}

int Form::getGradeToExecute() {
  return _gradeToExecute;
}

const char* Form::gradeTooHighException::what() const throw() {
  return "Grade is too high too proceed";
}

const char* Form::gradeTooLowException::what() const throw() {
  return "Grade is too low to proceed";
}

std::ostream& operator<<(std::ostream& str, Form& form) {
  return str  << "Form " << form.getName()
              << ", is signed: " << form.getIsSigned()
              << ". Requires grades of " << form.getGradeToSign()
              << " to sign and " << form.getGradeToExecute()
              << " to execute";
}

void Form::beSigned(Bureaucrat& b) {
  if (b.getGrade() <= _gradeToSign)
    _signed = true;
  else
    throw gradeTooLowException();
}
