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
	}
	fd = open("dft.bin", O_RDONLY|O_CREAT, 0777);
	for(i=0; i<200; i++){
	//	int pom = read_word(fd);
	//	void *a = (void *) &pom;
	//	dft[i][0] = *((float *) a);
	//	int pomm = read_word(fd);
	//	void *b = (void *) &pomm;
	//	dft[i][1] = *((float *) b);
		dft[i][0] = (float)read_word(fd);
        	dft[i][1] = (float)read_word(fd);
	}
	close(fd);
	cmplx_idft(dft, idft, 200);
	for (i=0;i<200;i++){
		printf("input je %f, idft je %f input img je %f idft img je%f\n", input[i][0], idft[i][0], input[i][1], idft[i][1]);
	}
	
	for (i=0; i<200; i++){
		if (input[i][0] != idft[i][0] || input[i][1] != idft[i][1]){
			printf("greska na %d. mjestu\n", (i+1));
			printf("input je %f, idft je %f\n", input[i][0], idft[i][0]);
			break;
		}
		
	}
	printf("gotov test nad inverznom DFT\n");
	return 0;
}
