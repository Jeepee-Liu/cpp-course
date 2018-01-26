include makefile.config
include $(SRC_DIR)/makefile.config

SRC_FILES = $(addprefix $(SRC_DIR)/,\
	$(addsuffix .hpp,$(SRC_NAMES)\
	)) $(addprefix $(SRC_DIR)/,\
	$(addsuffix .cpp,$(SRC_NAMES)\
	))

.PHONY : clean all play

all : $(TAR)

$(TAR) : $(addprefix $(SRC_DIR)/,$(SRC_OBJS)) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TAR) $(addprefix $(SRC_DIR)/,$(SRC_OBJS)) $(MAIN_OBJ)

$(MAIN_OBJ) : main.cpp $(addprefix $(SRC_DIR)/,$(SRC_OBJS))

$(addprefix $(SRC_DIR)/,$(SRC_OBJS)) : $(SRC_FILES)
	cd $(SRC_DIR) && make

play :
	echo $(SRC_FILES)

clean :
	$(RM) $(TAR) $(MAIN_OBJ)
	cd $(SRC_DIR) && (make clean)