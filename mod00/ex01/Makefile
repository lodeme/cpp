TARGET = phonebook
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g
OBJDIR = obj
SOURCES =	src/Contact.cpp \
			src/PhoneBook.cpp \
			src/main.cpp
OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(shell mkdir -p $(OBJDIR))

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
