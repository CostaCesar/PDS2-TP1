#debug mode
CDEBUG = 
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CDEBUG = -g3
else
    CDEBUG = -g0
endif

# tool macros
CXX ?= g++
CXXFLAGS := -Wall -std=c++17 $(CDEBUG)

# path macros
BIN_PATH := ./bin
OBJ_PATH := ./tmp
SRC_PATH := ./src
INC_PATH := ./inc
TST_PATH := ./test

# do not search these as files in the workspace
.PHONY: clean delete all tests run_tests test_board test_reversi

# use these
all: tests

tests: test_board test_reversi test_puzzle test_liga4

run_tests: tests
	$(BIN_PATH)/Board_Test
	$(BIN_PATH)/JogoVelha_Test
	$(BIN_PATH)/Reversi_Test
	$(BIN_PATH)/Puzzle_Test
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


clean:
	rm $(OBJ_PATH)/*.o
delete:
	rm $(BIN_PATH)/*_Test

# good luck (don't) use these
$(OBJ_PATH)/Piece.o: $(SRC_PATH)/Piece.cpp $(INC_PATH)/Piece.hpp $(INC_PATH)/Vec.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Piece.o -I$(INC_PATH)

$(OBJ_PATH)/Board.o: $(SRC_PATH)/Board.cpp $(INC_PATH)/Board.hpp $(INC_PATH)/Direction.hpp 
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

# object bin TEMPLATE:
# $(OBJ_PATH)/<example>.o: <required targets>
#	$(CXX) $(CXXFLAGS) -c <required files> -o $(OBJ_PATH)/<example> -I$(INC_PATH)

# final bin TEMPLATE:
# $(BIN_PATH)/<example>: <required targets>
#	$(CXX) $(CXXFLAGS) <required files> -o $(BIN_PATH)/<example> -I$(INC_PATH)
