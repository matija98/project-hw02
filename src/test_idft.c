#include <cmplx.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#define PI 3.14159

int main(){
	int fd, i;
	cmplx_t input[200], dft[200], idft[200];
	for (i=0; i<200; i++){
		input[i][0] = sin(PI*0.5*i);
		input[i][1] = 0;
		input[i][0] = input[i][0] == 0 ? 0 : input[i][0];
        	input[i][0] = roundf(input[i][0] * 10000) / 10000;
	}
	fd = open("dft.bin", O_RDONLY | O_CREAT, 0777);
	for(i=0; i<200; i++){
		int pom = read_word(fd);
		void *a = (void *) pom;
		dft[i][0] = *((float *) a);
		int pomm = read_word(fd);
		void *b = (void *) pomm;
		dft[i][1] = *((float *) b);
	}
	close(fd);
	cmplx_idft(dft, idft, 200);
	for (i=0; i<200; i++){
		if (input[i][0] != idft[i][0] || input[i][1] != idft[i][1]){
			printf("greska na %d. mjestu\n", (i+1));
			break;
		}
		
	}
	printf("gotov test nad inverznom DFT\n");
	return 0;
}
