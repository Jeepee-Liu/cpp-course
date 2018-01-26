CXX=g++ --std=c++14
CXXFLAG=-Wall -Wextra
SWN=SmallWorldNetwork
SWNI=SmallWorldNetworkIsing
OBJS=$(SWN).o $(SWNI).o
TARS=swn-test swni-test

# general commands

swni : swni-test
swn : swn-test

# executable files

swn-test : $(SWN).o swn-test.cpp
	$(CXX) $(CXXFLAG) -o swn-test $(SWN).o swn-test.cpp
swni-test : $(OBJS) swni-test.cpp
	$(CXX) $(CXXFLAG) -o swni-test $(SWN).o $(SWNI).o swni-test.cpp

# object files

$(SWN).o : $(SWN).hpp $(SWN).cpp
	$(CXX) $(CXXFLAG) -c $(SWN).cpp 
$(SWNI).o : $(SWNI).hpp $(SWNI).cpp
	$(CXX) $(CXXFLAG) -c $(SWNI).cpp

# phony commands

.PHONY : clean remake run-swn run-swni

clean : 
	rm -f $(TARS) $(OBJS)
remake :
	clear && make clean && make
run-swn :
	./swn-test
run-swni :
	./swni-test