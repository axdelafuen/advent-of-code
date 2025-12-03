CC=g++
SRC=$(wildcard *.cpp)  
EXE=a.out

FLAGS+=-Wall

OBJ=$(addprefix build/,$(SRC:.cpp=.o))

all: $(OBJ)
	$(CC) -o $(EXE) $^ $(FLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch a.out

