CXX = g++ --std=c++11
CFLAG = -Wall -Wextra
MAIN_SRC = main.cpp
MAIN_TARGET = main

$(MAIN_TARGET) : $(MAIN_SRC)
	$(CXX) $(CFLAG) $(MAIN_SRC) -o $(MAIN_TARGET)

.PHONY : clean remake run

clean :
	rm -rf $(MAIN_TARGET)

remake :
	make clean && clear && make

run :
	./$(MAIN_TARGET)