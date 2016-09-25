CXX=g++

main : main.o
	$(CXX) -o gcd_main main.o

main.o : main.cpp
	$(CXX) -c main.cpp
	
PHONY : clean
clean : 
	rm -rf main.o gcd_main