include makefile.config

$(MAIN_TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN_TARGET)

main.o : main.h
	$(CXX) $(STD) $(CFLAG) -c main.cpp  -o main.o

randomWalk.o :
	cd $(SRC_DIR) && make

.PHONY : clean remake
# phony commands
clean :
	rm -rf $(MAIN_TARGET) $(OBJS)
remake :
	clear && make clean && make
