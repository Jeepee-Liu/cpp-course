include makefile.config

$(MAIN_TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN_TARGET)

main.o : 
	$(CXX) $(CFLAG) $(STD) -c main.cpp  -o main.o

testPrint.o : 
	cd $(SRC_DIR1) && $(MAKE)

.PHONY : clean
clean :
	rm -r $(MAIN_TARGET) $(OBJS)
