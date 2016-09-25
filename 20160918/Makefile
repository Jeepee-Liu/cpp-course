include makefile.config

$(MAIN_TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN_TARGET)

main.o : 
	$(CXX) $(CFLAG) $(STD) -c main.cpp  -o main.o

testPrint.o : 
	cd $(SRC_DIR1) && make

formatOutput.o :
	cd $(SRC_DIR2) && make


.PHONY : clean remake
# phony commands
clean :
	rm -rf $(MAIN_TARGET) $(OBJS)

remake :
	clear && make clean && make
