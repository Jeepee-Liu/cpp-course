CCOPTION = Wall Wextra std=gnu++11
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ = MyVector.o randomWalk.o 
SRC_DIR = /Users/jeepee/Documents/Cpp_trade/cpp-course/20161118/src

output.out: $(OBJ) 
	 $(CC) $(FLAGS) $(OBJ) -o output.out 

MyVector.o: $(SRC_DIR)\MyVector.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\MyVector.cpp -o MyVector.o 

randomWalk.o: $(SRC_DIR)\randomWalk.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\randomWalk.cpp -o randomWalk.o 


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out
