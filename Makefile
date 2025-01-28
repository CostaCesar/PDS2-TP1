#debug mode
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CDEBUG = -g3
else
    CDEBUG = -g0
endif

#os detection
ifeq ($(OS),Windows_NT)
	RM = del
	SL = \\
	DOXYGEN = doxygen.exe
else
	RM = rm
	SL = /
	DOXYGEN = doxygen
endif

# tool macros
CXX ?= g++
CXXFLAGS := -Wall -std=c++11 $(CDEBUG)

# path macros
BIN_PATH := .$(SL)bin
OBJ_PATH := .$(SL)tmp
SRC_PATH := .$(SL)src
INC_PATH := .$(SL)inc
TST_PATH := .$(SL)test

# available targets to use
# (make does not search these as files in the workspace)
.PHONY: clean delete all tests doc \
board velha reversi puzzle velha_inf \
lib_test test_board test_reversi test_puzzle test_liga4 test_velha

# executables
all: tests main

main: manager board velha liga4 reversi puzzle velha_inf $(SRC_PATH)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRC_PATH)/main.cpp $(MANAGER) $(BOARD) $(LIGA4) $(VELHA) $(RANDOM) $(REVERSI) $(PUZZLE) $(VELHA_INF) -o $(BIN_PATH)/main -I$(INC_PATH)

tests: lib_test lib_random board puzzle liga4 reversi velha velha_inf $(OBJ_PATH)/Velha_Test.o $(MANAGER_TEST) \
$(OBJ_PATH)/Liga4_Test.o $(OBJ_PATH)/Puzzle_Test.o $(OBJ_PATH)/Velha_Infinity_Test.o $(MANAGER_TEST)
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Velha_Test.o $(OBJ_PATH)/Reversi_Test.o $(OBJ_PATH)/Liga4_Test.o $(OBJ_PATH)/Puzzle_Test.o \
	$(OBJ_PATH)/Velha_Infinity_Test.o $(OBJ_PATH)/Register_Test.o $(BOARD) $(PUZZLE) $(LIGA4) $(VELHA) $(VELHA_INF) $(REVERSI) $(RANDOM) $(MANAGER) -o $(BIN_PATH)/Full_Test

	$(BIN_PATH)/Full_Test


test_board: lib_test board $(OBJ_PATH)/Board_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Board_Test.o $(BOARD) -o $(BIN_PATH)/Board_Test
	$(BIN_PATH)/Board_Test

test_velha: lib_test board velha $(OBJ_PATH)/Velha_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Velha_Test.o $(BOARD) $(VELHA) -o $(BIN_PATH)/Velha_Test
	$(BIN_PATH)/Velha_Test

test_reversi: lib_test board reversi $(OBJ_PATH)/Reversi_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Reversi_Test.o $(BOARD) $(REVERSI) -o $(BIN_PATH)/Reversi_Test
	$(BIN_PATH)/Reversi_Test

test_liga4: lib_test board liga4 $(OBJ_PATH)/Liga4_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Liga4_Test.o $(BOARD) $(LIGA4) -o $(BIN_PATH)/Liga4_Test
	$(BIN_PATH)/Liga4_Test

test_puzzle: lib_test board puzzle lib_random $(OBJ_PATH)/Puzzle_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Puzzle_Test.o $(BOARD) $(PUZZLE) $(RANDOM) -o $(BIN_PATH)/Puzzle_Test
	$(BIN_PATH)/Puzzle_Test

test_velha_infinity: lib_test board velha velha_inf $(OBJ_PATH)/Velha_Infinity_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Velha_Infinity_Test.o $(BOARD) $(VELHA) $(VELHA_INF) -o $(BIN_PATH)/Velha_Infinity_Test
	$(BIN_PATH)/Velha_Infinity_Test

test_register: lib_test manager $(OBJ_PATH)/Register_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Register_Test.o $(OBJ_PATH)/Register.o -o $(BIN_PATH)/Register_Test
	$(BIN_PATH)/Register_Test

test_admin: lib_test manager $(OBJ_PATH)/Admin_Test.o board puzzle liga4 reversi velha velha_inf
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Lib_Test.o $(OBJ_PATH)/Admin_Test.o $(MANAGER) $(BOARD) $(LIGA4) $(VELHA) $(RANDOM) $(REVERSI) $(PUZZLE) $(VELHA_INF) -o $(BIN_PATH)/Admin_Test
	$(BIN_PATH)/Admin_Test

# util
doc:
	./doxygen/$(DOXYGEN)
clean:
	$(RM) $(OBJ_PATH)$(SL)*.o
delete:
	$(RM) $(BIN_PATH)$(SL)*_Test
	$(RM) $(BIN_PATH)$(SL)*.exe

# good luck (don't) use these
lib_test: $(OBJ_PATH)/Lib_Test.o

lib_random: $(SRC_PATH)/Random.cpp $(INC_PATH)/Random.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Random.cpp -o $(OBJ_PATH)/Random.o -I$(INC_PATH)
RANDOM = $(OBJ_PATH)/Random.o

$(OBJ_PATH)/Lib_Test.o: $(TST_PATH)/TestHeader.cpp $(TST_PATH)/TestHeader.hpp 
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/TestHeader.cpp -o $(OBJ_PATH)/Lib_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Register.o: $(SRC_PATH)/Register.cpp $(INC_PATH)/Register.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Register.cpp -o $(OBJ_PATH)/Register.o -I$(INC_PATH)

$(OBJ_PATH)/Register_Test.o: $(TST_PATH)/Register_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Register_Test.cpp -o $(OBJ_PATH)/Register_Test.o -I$(INC_PATH)

$(OBJ_PATH)/Admin.o: $(SRC_PATH)/Admin.cpp $(INC_PATH)/Admin.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Admin.cpp -o $(OBJ_PATH)/Admin.o -I$(INC_PATH)

$(OBJ_PATH)/Admin_Test.o: $(TST_PATH)/Admin_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Admin_Test.cpp -o $(OBJ_PATH)/Admin_Test.o -I$(INC_PATH)

manager: $(OBJ_PATH)/Register.o $(OBJ_PATH)/Admin.o
MANAGER = $(OBJ_PATH)/Register.o $(OBJ_PATH)/Admin.o
MANAGER_TEST = $(OBJ_PATH)/Register_Test.o $(OBJ_PATH)/Admin_Test.o


$(OBJ_PATH)/Piece.o: $(SRC_PATH)/Piece.cpp $(INC_PATH)/Piece.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Piece.o -I$(INC_PATH)

$(OBJ_PATH)/Board.o: $(SRC_PATH)/Board.cpp $(INC_PATH)/Board.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Board.cpp -o $(OBJ_PATH)/Board.o -I$(INC_PATH)

$(OBJ_PATH)/Board_Test.o: $(TST_PATH)/Board_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Board_Test.cpp -o $(OBJ_PATH)/Board_Test.o -I$(INC_PATH)

board: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o
BOARD = $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o


$(OBJ_PATH)/Game_Velha.o: $(SRC_PATH)/Game_Velha.cpp $(INC_PATH)/Game_Velha.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Velha.cpp -o $(OBJ_PATH)/Game_Velha.o -I$(INC_PATH)

$(OBJ_PATH)/Velha_Test.o: $(TST_PATH)/Velha_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Velha_Test.cpp -o $(OBJ_PATH)/Velha_Test.o -I$(INC_PATH)

velha: $(OBJ_PATH)/Game_Velha.o
VELHA = $(OBJ_PATH)/Game_Velha.o


$(OBJ_PATH)/Game_Reversi.o: $(SRC_PATH)/Game_Reversi.cpp $(INC_PATH)/Game_Reversi.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Reversi.cpp -o $(OBJ_PATH)/Game_Reversi.o -I$(INC_PATH)

$(OBJ_PATH)/Reversi_Test.o: $(TST_PATH)/Reversi_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Reversi_Test.cpp -o $(OBJ_PATH)/Reversi_Test.o -I$(INC_PATH)

reversi: $(OBJ_PATH)/Game_Reversi.o
REVERSI = $(OBJ_PATH)/Game_Reversi.o


$(OBJ_PATH)/Game_Liga4.o: $(SRC_PATH)/Game_Liga4.cpp $(INC_PATH)/Game_Liga4.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Liga4.cpp -o $(OBJ_PATH)/Game_Liga4.o -I$(INC_PATH)

$(OBJ_PATH)/Liga4_Test.o: $(TST_PATH)/Liga4_Test.cpp 
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Liga4_Test.cpp -o $(OBJ_PATH)/Liga4_Test.o -I$(INC_PATH)

liga4: $(OBJ_PATH)/Game_Liga4.o
LIGA4 = $(OBJ_PATH)/Game_Liga4.o


$(OBJ_PATH)/Game_Puzzle.o: $(SRC_PATH)/Game_Puzzle.cpp $(INC_PATH)/Game_Puzzle.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Puzzle.cpp -o $(OBJ_PATH)/Game_Puzzle.o -I$(INC_PATH)

$(OBJ_PATH)/Puzzle_Test.o: $(TST_PATH)/Puzzle_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Puzzle_Test.cpp -o $(OBJ_PATH)/Puzzle_Test.o -I$(INC_PATH)

puzzle: $(OBJ_PATH)/Game_Puzzle.o
PUZZLE = $(OBJ_PATH)/Game_Puzzle.o

$(OBJ_PATH)/Game_Velha_Infinity.o: $(SRC_PATH)/Game_Velha_Infinity.cpp $(INC_PATH)/Game_Velha_Infinity.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Velha_Infinity.cpp -o $(OBJ_PATH)/Game_Velha_Infinity.o -I$(INC_PATH)

$(OBJ_PATH)/Velha_Infinity_Test.o: $(TST_PATH)/Velha_Infinity_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Velha_Infinity_Test.cpp -o $(OBJ_PATH)/Velha_Infinity_Test.o -I$(INC_PATH)

velha_inf: $(OBJ_PATH)/Game_Velha_Infinity.o
VELHA_INF = $(OBJ_PATH)/Game_Velha_Infinity.o

# templates

# object bin TEMPLATE:
# $(OBJ_PATH)/<example>.o: <required targets>
#	$(CXX) $(CXXFLAGS) -c <required files> -o $(OBJ_PATH)/<example> -I$(INC_PATH)

# final bin TEMPLATE:
# $(BIN_PATH)/<example>: <required targets>
#	$(CXX) $(CXXFLAGS) <required files> -o $(BIN_PATH)/<example> -I$(INC_PATH)