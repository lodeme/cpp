TARGET = diamondtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -Iinclude -g
OBJDIR = obj
SOURCES =	src/main.cpp \
					src/ClapTrap.cpp \
					src/FragTrap.cpp \
					src/DiamondTrap.cpp
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
