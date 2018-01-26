CXX = g++ --std=c++11
ifeq ($(DEF),DEBUG)
	CXXFLAGS = -Wall -Wextra -g -ferror-limit=5
else
	CXXFLAGS = -O3
endif
RM = rm -f

.SUFFIXES = .cpp .o
.cpp.o : 
	$(CXX) $(CXXFLAGS) -c $< -o $@

SRC_DIR = src
BINS = main
OBJS = $(SRC_DIR)/pdbIO.o\
	$(SRC_DIR)/Residue.o\
	$(SRC_DIR)/Interaction.o

.PHONY = all clean

all : $(BINS)

test : main.cpp
	$(CXX) $(CXXFLAGS) -o test main.cpp

$(BINS) : main.cpp $(OBJS) main.hpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(OBJS)

$(OBJS) : $(patsubst %.o,%.cpp,$@)

clean :
	$(RM) $(BINS) $(OBJS) $(BINS) test