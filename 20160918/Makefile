include makefile.config

$(MAIN_TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN_TARGET)

main.o : 
	$(CXX) $(CFLAG) $(STD) -c main.cpp  -o main.o

testPrint.o : 
	cd $(SRC_DIR1) && $(MAKE)

formatOutput.o :
	cd $(SRC_DIR2) && $(MAKE)

.PHONY : clean remake

clean :
	rm -rf $(MAIN_TARGET) $(OBJS)

remake :
	make clean && make && clear
