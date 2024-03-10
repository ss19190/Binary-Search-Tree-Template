CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

TARGET = main

$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(BINDIR)
