include ../makefile.config
include makefile.config

all : $(SRC_OBJS)

$(SRC_OBJS) : setting.hpp setting.cpp

IsingSquare.o : IsingSquare.hpp IsingSquare.cpp setting.o

.PHONY : clean
clean : 
	$(RM) $(SRC_OBJS)