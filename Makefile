SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/

CFLAGS=-I $(INC)
#EXE=exe/app.elf

.SECONDARY:

all: $(SRC:.c=)

%.elf: $(OBJ)
	gcc $(OBJ) -o $@ -lm

%.o: %.c
	gcc -c $^ $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(SRC:.c=)

run: ./exe/*.elf
