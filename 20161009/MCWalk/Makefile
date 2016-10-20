# This CLASS is Usually used as a package
include ../makefile.config

$(PKG).o : $(PKG).h ../main.h
	$(CXX) $(STD) $(CFLAG) -c $(PKG).cpp -o ../$(PKG).o

.PHONY : clean
clean :
	rm -rf ../$(PKG).o