# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRCDIR = .
BUILDDIR = build
BINDIR = bin
LIBDIR = lib

# Source files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Matrice.cpp
# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
# Import files
IMPORT = $(LIBDIR)/%.h

# Executable name
EXECUTABLE = $(BINDIR)/main.exe

all: $(EXECUTABLE)

echo :
	echo on
	make all

run : $(EXECUTABLE)
	echo run $(EXECUTABLE)
	./$(EXECUTABLE)

installLib: 
	@mkdir -p $(LIBDIR)
	curl -LJO https://github.com/nothings/stb/raw/master/stb_image.h 
	@mv stb_image.h lib/

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

cleanLib:
	@rm -rf lib/*

.PHONY: all echo run installLib clean cleanLib
