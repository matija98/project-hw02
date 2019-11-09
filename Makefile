EXESRC=$(wildcard exesrc/*c)
SRC=$(wildcard src/*c)

OBJ=$(patsubst %c, %o, $(SRC))
EXEOBJ=$(patsubst %c, %o, $(EXESRC))
EXE=$(patsubst %c, %elf, $(EXESRC))

INC=inc/
CFLAGS=-I $(INC)

.SECONDARY:

all: $(EXE)

$(EXE): $(EXEOBJ)
	gcc -DEXECUTABLE_NAME=\"$@\" $< -o $@ -lm

%.o: $(SRC) $(EXESRC)
	gcc -c $^ $(CFLAGS) -o $@ -lm

clean:
	rm -f $(OBJ) $(EXEOBJ)

#run: ./exe/*.elf
