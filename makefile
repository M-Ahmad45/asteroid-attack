CXX = g++ #set the compiler
CXXFLAGS = -Wall #compiler flags
LIBS = -lSDL2
PROJDIR :=  .
SRCDIR := $(PROJDIR)/src
BINDIR := $(PROJDIR)/bin

BUILDDIR = $(BINDIR)/build
TARGET = $(BUILDDIR)/main
#wildcard function is used to get all the cpp file
SRCS := $(wildcard $(SRCDIR)/*.cpp)
#replace everything that matches $(SRCDIR)/%.cpp with $(BINDIR)/obj/%.o from the list $(SRCS)   
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/obj/%.o, $(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

$(BINDIR)/obj/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@

.PHONY: clean

clean: 
	rm -f $(OBJS)
	rm -f $(TARGET)
	