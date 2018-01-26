SRC_DIR = src
CXX = g++ -std=c++11
ifeq ($(DEF),DEBUG)
	CXXFLAGS = -Wall -Wextra -g
else
	CXXFLAGS =  -O3
endif
CXXFLAGS += -I $(SRC_DIR)
RM = rm -f

OBJ = main.o $(SRC_DIR)/BrownianMotion.o

.PHONY : all clean

all : main

main : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o : $(SRC_DIR)/BrownianMotion.cpp $(SRC_DIR)/BrownianMotion.h
$(SRC_DIR)/BrownianMotion.o : $(SRC_DIR)/BrownianMotion.h

clean :
	$(RM) $(OBJ) main