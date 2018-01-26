CXX = g++ --std=c++11
CXXFLAG = -Wall -Wextra
TAR = main

main :
	$(CXX) $(CXXFLAG) main.cpp -o $(TAR)

.PHONY = clean remake run

clean :
	rm -f $(TAR) $(OBJS)

remake :
	clear && make clean && make

run :
	./$(TAR)

