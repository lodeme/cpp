TARGET = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g
OBJDIR = obj
SOURCES =	src/Contact.cpp \
			src/PhoneBook.cpp \
			src/main.cpp
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
	rm -rf $(OBJDIR) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
