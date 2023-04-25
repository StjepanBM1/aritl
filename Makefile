CC=g++

override BIN := aritl
override CPP := $(shell find ./ -type f -name '*.cpp')
override OBJ := $(CPP:.cpp=.o)

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.cpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm $(BIN) $(OBJ)
