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

all: tests
tests: test_board test_reversi
	$(BIN_PATH)/Board_Test
	$(BIN_PATH)/Reversi_Test

clean:
	rm $(OBJ_PATH)/*.o

Piece.o: $(SRC_PATH)/Piece.cpp $(INC_PATH)/Piece.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Piece.o -I$(INC_PATH)

Board.o: $(SRC_PATH)/Board.cpp $(INC_PATH)/Board.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Board.cpp -o $(OBJ_PATH)/Board.o -I$(INC_PATH)

Game_Reversi.o: $(SRC_PATH)/Game_Reversi.cpp $(INC_PATH)/Game_Reversi.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Game_Reversi.cpp -o $(OBJ_PATH)/Game_Reversi.o -I$(INC_PATH)

test_reversi: Board.o Piece.o Game_Reversi.o $(TST_PATH)/Reversi_Test.cpp
	$(CXX) $(CXXFLAGS) $(TST_PATH)/Reversi_Test.cpp $(OBJ_PATH)/Board.o $(OBJ_PATH)/Game_Reversi.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Reversi_Test -I$(INC_PATH)

test_board: Board.o Piece.o $(TST_PATH)/Board_Test.cpp
	$(CXX) $(CXXFLAGS) $(TST_PATH)/Board_Test.cpp $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Board_Test -I$(INC_PATH)