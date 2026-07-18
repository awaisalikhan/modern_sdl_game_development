CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -I../../External/SDL/include -I../../External/SDL/include/SDL -I../../External/SDL_image/include/SDL2 -I./include

LDFLAGS = -static-libgcc -static-libstdc++ -L../../External/SDL/lib/win/x64 -L../../External/SDL_image/lib/win/x64 -lmingw32 -lSDL2main -lSDL2_image -lSDL2

#SRC := $(wildcard *.cpp)
SRC := Game.cpp main.cpp
BIN_DIR = ../bin
OUT = $(BIN_DIR)/game.exe
SDL_IMAGE_DLL = ../../External/SDL_image/bin/win/x64/SDL2_image.dll
SDL_IMAGE_DLL_DEST = $(BIN_DIR)/SDL2_image.dll

all: $(BIN_DIR) $(SDL_IMAGE_DLL_DEST) $(OUT)

$(BIN_DIR):
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

$(SDL_IMAGE_DLL_DEST): $(SDL_IMAGE_DLL)
	copy /Y "..\..\External\SDL_image\bin\win\x64\SDL2_image.dll" "..\bin\SDL2_image.dll"

run: all
	$(OUT)

clean:
	if exist "$(OUT)" del /Q "$(OUT)"
