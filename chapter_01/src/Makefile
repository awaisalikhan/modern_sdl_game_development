CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -I../../External/SDL/include -I./include

LDFLAGS = -static-libgcc -static-libstdc++ -L../../External/SDL/lib/win/x64 -lmingw32 -lSDL2main -lSDL2

SRC := $(wildcard *.cpp)
BIN_DIR = ../bin
OUT = $(BIN_DIR)/game.exe

all: $(BIN_DIR) $(OUT)

$(BIN_DIR):
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run: all
	$(OUT)

clean:
	if exist "$(OUT)" del /Q "$(OUT)"
