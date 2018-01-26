CXX = g++ --std=c++14
CXXFLAG = -Wall -Wextra
SRC_DIR = ./swn
OBJS = $(SRC_DIR)/SmallWorldNetwork.o
TAR = main
INC = $(SRC_DIR)

$(TAR) : $(OBJS)
	$(CXX) $(CXXFLAG) main.cpp -o $(TAR) -I $(INC)

SmallWorldNetwork.o : SmallWorldNetwork.hpp
	$(CXX) $(CXXFLAG) -c SmallWorldNetwork.cpp

.PHONY = clean remake run

clean :
	rm -f $(OBJS) $(TAR)

remake :
	make clean && clear && make

run :
	./$(TAR)