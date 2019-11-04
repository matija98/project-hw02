#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_word(int fd){
	int procitano;
	if (read(fd, &procitano, sizeof procitano) < 0){
		printf("greska u citanju\n");
		return -1;
	}
	return procitano;
}

short read_half(int fd){
	short procitano;
	if (read(fd, &procitano, sizeof procitano) < 0){
		printf("greska u citanju\n");
		return -1;
	}
	return procitano;
}

void write_word(int fd, int word){
	if (write(fd, &word, sizeof word) < 0)
		printf("greska u pisanju\n");
}

void write_half(int fd, short word){
	if (write(fd, &word, sizeof word) < 0)
		printf("greska u pisanju\n");
}

