CC=g++
CCFLAGS= -std=c++11
LIBFLAGS= -lSDL -lSDL_ttf -std=c++11
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= exe

all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $^ -o $@   $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) 

rmproper:
	rm -f $(EXEC)

