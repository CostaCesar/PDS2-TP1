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

all: tests main

tests: test_board
	$(BIN_PATH)/Board_Test

clean:
	rm $(OBJ_PATH)/*.o

Board.o: $(SRC_PATH)/Board.cpp $(INC_PATH)/Board.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Board.cpp -o $(OBJ_PATH)/Board.o -I$(INC_PATH)

Piece.o: $(SRC_PATH)/Piece.cpp $(INC_PATH)/Piece.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Piece.o -I$(INC_PATH)

Player.o: $(SRC_PATH)/Player.cpp $(INC_PATH)/Player.hpp
	$(CXX) $(SRC_PATH) -c $(SRC_PATH)/Piece.cpp -o $(OBJ_PATH)/Player.o -I$(INC_PATH)

Register.o: $(SRC_PATH)/Register.cpp 
	$(CXX) $(SRC_PATH) -c $(SRC_PATH)/Register.cpp -o $(OBJ_PATH)/Register.o -I$(INC_PATH)

JogoVelha.o: $(INC_PATH)/Board.hpp $(SRC_PATH)/Velha.cpp $(INC_PATH)/Velha.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/Velha.cpp -o $(OBJ_PATH)/Velha.o -I$(INC_PATH)

main.o: $(SRC_PATH)/main.cpp $(SRC_PATH)/Register.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/main.cpp -o $(OBJ_PATH)/main.o -I$(INC_PATH)

main: $(OBJ_PATH)/main.o
	$(CXX) $(CXXFLAGS) $(OBJ_PATH)/main.o -o $(BIN_PATH)/main
	
test_board: Board.o Piece.o $(TST_PATH)/Board_Test.cpp
	$(CXX) $(CXXFLAGS) $(TST_PATH)/Board_Test.cpp $(OBJ_PATH)/Board.o $(OBJ_PATH)/Piece.o -o $(BIN_PATH)/Board_Test -I$(INC_PATH)
