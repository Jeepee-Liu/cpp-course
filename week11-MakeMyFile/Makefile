CXX = g++ --std=c++11
SRC_DIR = ./src
INC =  -I$(SRC_DIR)
RM = rm -f
OBJS = $(SRC_DIR)/MyVector.o\
	$(SRC_DIR)/randomWalk.o\
	rwdist.o rwtime.o main.o
BINS = main rwdist rwtime

ifeq ($(DEF), DEBUG)
	CXXFLAGS = -g -Wall -Wextra
else
	ifeq ($(DEF), PROF)
		CXXFLAGS = -O3 -pg
	else
		CXXFLAGS = -O3
	endif
endif

#####################################
# .SUFFIXES : .o .cpp .h
# .cpp.o :
# 	$(CXX) $(CXXFLAGS) $(INC) -c $<
#####################################

.PHONY : all clean

all : $(BINS)

#####################################

rwdist : rwdist.o $(SRC_DIR)/MyVector.o\
	$(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o rwdist $^

rwtime : rwtime.o $(SRC_DIR)/MyVector.o\
	$(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o rwtime $^

main : main.o $(SRC_DIR)/MyVector.o\
	$(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o main $^

# $(OBJS) : $(patsubst %.o,%.cpp,$(OBJS))

$(SRC_DIR)/MyVector.o : $(SRC_DIR)/MyVector.h
	$(CXX) $(CXXFLAGS) $(INC) -o $(SRC_DIR)/MyVector.o -c $(SRC_DIR)/MyVector.cpp
$(SRC_DIR)/randomWalk.o : $(SRC_DIR)/randomWalk.h
	$(CXX) $(CXXFLAGS) $(INC) -o $(SRC_DIR)/randomWalk.o -c $(SRC_DIR)/randomWalk.cpp 
main.o : main.cpp $(SRC_DIR)/MyVector.o $(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c main.cpp
rwdist.o : rwdist.cpp $(SRC_DIR)/MyVector.o $(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c rwdist.cpp
rwtime.o : rwtime.cpp $(SRC_DIR)/MyVector.o $(SRC_DIR)/randomWalk.o
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c rwtime.cpp

#####################################

clean : 
	$(RM) $(OBJS) $(BINS)

