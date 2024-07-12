CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS =
SRCDIR = src
INCDIR = include
BINDIR = bin

# Directories and sources
SOURCES := $(wildcard $(SRCDIR)/*.cpp) \
           $(wildcard $(SRCDIR)/compression/*.cpp) \
           $(wildcard $(SRCDIR)/decrypt/*.cpp) \
           $(wildcard $(SRCDIR)/encrypt/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SOURCES))
EXECUTABLE := $(BINDIR)/fequip

# Make rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
