CXX = g++ --std=c++11
CFLAG = -Wall -Wextra
OBJS = main.o MyString.o

main : $(OBJS)
	$(CXX) $(CFLAG) $(OBJS) -o main

main.o : MyString.o
	$(CXX) $(CFLAG) -c main.cpp -o main.o

MyString.o : MyString.h
	$(CXX) $(CFLAG) -c MyString.cpp -o MyString.o

.PHONY : clean remake

clean :
	rm -f main $(OBJS)

remake :
	clear && make clean && make