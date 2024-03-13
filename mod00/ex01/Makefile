# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

# Name of the executable
TARGET = phonebook

# Directory for object files
OBJDIR = obj

# Source files
SOURCES = src/Contact.cpp src/PhoneBook.cpp src/main.cpp

# Object files (placed in OBJDIR)
OBJECTS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Create the OBJDIR if it does not exist
$(shell mkdir -p $(OBJDIR))

# Link the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Phony targets
.PHONY: all clean
