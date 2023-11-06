# Makefile for your C++ project

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRCDIR = .
BUILDDIR = build
BINDIR = bin

# Source files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Matrice.cpp
# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
# Executable name
EXECUTABLE = $(BINDIR)/main.exe

all: $(EXECUTABLE)
	echo off

run : $(EXECUTABLE)
	echo run $(EXECUTABLE)
	./$(EXECUTABLE)

# Rule for linking object files and creating the executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for compiling source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build
clean:
	@rm -rf $(BUILDDIR) $(BINDIR)