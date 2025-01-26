#debug mode
CDEBUG = 
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
CXXFLAGS := -Wall -std=c++17 $(CDEBUG)

# path macros
BIN_PATH := .$(SL)bin
OBJ_PATH := .$(SL)tmp
SRC_PATH := .$(SL)src
INC_PATH := .$(SL)inc
TST_PATH := .$(SL)test

# do not search these as files in the workspace
.PHONY: clean delete all tests run_tests doc test_board test_reversi test_puzzle test_liga4 test_velha

# use these
all: main tests

tests: test_board test_reversi test_puzzle test_liga4 test_velha

doc:
	./doxygen/$(DOXYGEN)

run_tests: tests
	$(BIN_PATH)/Board_Test
	$(BIN_PATH)/Puzzle_Test
	$(BIN_PATH)/Reversi_Test
	$(BIN_PATH)/Velha_Test
	$(BIN_PATH)/Velha_Infinity_Test
	$(BIN_PATH)/Liga4_Test

test_board: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Board_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Board_Test.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Board_Test

test_velha: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Velha.o $(OBJ_PATH)/Velha_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Velha_Test.o $(OBJ_PATH)/Game_Velha.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Velha_Test

test_reversi: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Reversi.o $(OBJ_PATH)/Reversi_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Reversi_Test.o $(OBJ_PATH)/Game_Reversi.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Reversi_Test

test_liga4: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Liga4.o $(OBJ_PATH)/Liga4_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Liga4_Test.o $(OBJ_PATH)/Game_Liga4.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Liga4_Test

test_puzzle: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Puzzle.o $(OBJ_PATH)/Puzzle_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Puzzle_Test.o $(OBJ_PATH)/Game_Puzzle.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Puzzle_Test

test_velha_infinity: $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Velha.o $(OBJ_PATH)/Game_Velha_Infinity.o $(OBJ_PATH)/Velha_Infinity_Test.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/Velha_Infinity_Test.o $(OBJ_PATH)/Game_Velha_Infinity.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Game_Velha.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Velha_Infinity_Test

clean:
	$(RM) $(OBJ_PATH)$(SL)*.o
delete:
	$(RM) $(BIN_PATH)$(SL)*_Test
	$(RM) $(BIN_PATH)$(SL)*.exe

main: $(OBJ_PATH)/Register.o $(OBJ_PATH)/Admin.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Reversi.o $(OBJ_PATH)/Game_Liga4.o $(OBJ_PATH)/Game_Velha.o
	$(CXX) $(CXXFLAGS) $(SRC_PATH)/main.cpp $(OBJ_PATH)/Register.o $(OBJ_PATH)/Admin.o $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o $(OBJ_PATH)/Game_Reversi.o $(OBJ_PATH)/Game_Liga4.o $(OBJ_PATH)/Game_Velha.o -o $(BIN_PATH)/main -I$(INC_PATH)

# good luck (don't) use these
$(OBJ_PATH)/Register.o: $(SRC_PATH)/Register.cpp $(INC_PATH)/Register.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Register.cpp -o $(OBJ_PATH)/Register.o -I$(INC_PATH)

$(OBJ_PATH)/Admin.o: $(SRC_PATH)/Admin.cpp $(INC_PATH)/Admin.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Admin.cpp -o $(OBJ_PATH)/Admin.o -I$(INC_PATH)

$(OBJ_PATH)/Piece.o: $(SRC_PATH)/Piece.cpp $(INC_PATH)/Piece.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Piece.o -I$(INC_PATH)


$(OBJ_PATH)/Board.o: $(SRC_PATH)/Board.cpp $(INC_PATH)/Board.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Board.cpp -o $(OBJ_PATH)/Board.o -I$(INC_PATH)

$(OBJ_PATH)/Board_Test.o: $(TST_PATH)/Board_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Board_Test.cpp -o $(OBJ_PATH)/Board_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Game_Velha.o: $(SRC_PATH)/Game_Velha.cpp $(INC_PATH)/Game_Velha.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Velha.cpp -o $(OBJ_PATH)/Game_Velha.o -I$(INC_PATH)

$(OBJ_PATH)/Velha_Test.o: $(TST_PATH)/Velha_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Velha_Test.cpp -o $(OBJ_PATH)/Velha_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Game_Reversi.o: $(SRC_PATH)/Game_Reversi.cpp $(INC_PATH)/Game_Reversi.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Reversi.cpp -o $(OBJ_PATH)/Game_Reversi.o -I$(INC_PATH)

$(OBJ_PATH)/Reversi_Test.o: $(TST_PATH)/Reversi_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Reversi_Test.cpp -o $(OBJ_PATH)/Reversi_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Game_Liga4.o: $(SRC_PATH)/Game_Liga4.cpp $(INC_PATH)/Game_Liga4.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Liga4.cpp -o $(OBJ_PATH)/Game_Liga4.o -I$(INC_PATH)

$(OBJ_PATH)/Liga4_Test.o: $(TST_PATH)/Liga4_Test.cpp 
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Liga4_Test.cpp -o $(OBJ_PATH)/Liga4_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Game_Puzzle.o: $(SRC_PATH)/Game_Puzzle.cpp $(INC_PATH)/Game_Puzzle.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Puzzle.cpp -o $(OBJ_PATH)/Game_Puzzle.o -I$(INC_PATH)

$(OBJ_PATH)/Puzzle_Test.o: $(TST_PATH)/Puzzle_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Puzzle_Test.cpp -o $(OBJ_PATH)/Puzzle_Test.o -I$(INC_PATH)


$(OBJ_PATH)/Game_Velha_Infinity.o: $(SRC_PATH)/Game_Velha_Infinity.cpp $(INC_PATH)/Game_Velha_Infinity.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Velha_Infinity.cpp -o $(OBJ_PATH)/Game_Velha_Infinity.o -I$(INC_PATH)

$(OBJ_PATH)/Velha_Infinity_Test.o: $(TST_PATH)/Velha_Infinity_Test.cpp
	$(CXX) $(CXXFLAGS) -c $(TST_PATH)/Velha_Infinity_Test.cpp -o $(OBJ_PATH)/Velha_Infinity_Test.o -I$(INC_PATH)


# object bin TEMPLATE:
# $(OBJ_PATH)/<example>.o: <required targets>
#	$(CXX) $(CXXFLAGS) -c <required files> -o $(OBJ_PATH)/<example> -I$(INC_PATH)

# final bin TEMPLATE:
# $(BIN_PATH)/<example>: <required targets>
#	$(CXX) $(CXXFLAGS) <required files> -o $(BIN_PATH)/<example> -I$(INC_PATH)