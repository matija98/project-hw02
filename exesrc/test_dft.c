#include <cmplx.h>
#include <io.h>
#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PI 3.14159

int main(){
	int fd, i;
	cmplx_t input[200], dft[200];
	for (i=0; i<200; i++){
		input[i][0] = sin(PI*0.5*i);
		input[i][1] = 0;
	}
	cmplx_dft(input, dft, 200);
	fd = open("dft.bin", O_WRONLY | O_CREAT, S_IRWXU);
	for(i=0; i<200; i++){
		//void *a = (void *) dft+i;
		//int pom = *((int *) a);
		//write_word(fd, pom);
		write_word(fd, (int)dft[i][0]);
        	write_word(fd, (int)dft[i][1]);
	}
	close(fd);
	return 0;
}
