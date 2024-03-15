TARGET = bankster
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude
OBJDIR = obj
SOURCES =	src/Account.cpp \
			src/tests.cpp
OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(shell mkdir -p $(OBJDIR))

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
