TARGET = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g
OBJDIR = obj
SOURCES =	src/Bureaucrat.cpp \
					src/main.cpp \
					src/AForm.cpp \
					src/ShrubberyCreationForm.cpp\
					src/RobotomyRequestForm.cpp \
					src/PresidentialPardonForm.cpp \
					src/Intern.cpp
OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJECTS): | $(OBJDIR)

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
