#include <cmplx.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	cmplx_t prob_a, prob_b;
	cmplx_t izlaz;
	prob_a[0]=3;
	prob_a[1]=4;
	prob_b[0]=12;
	prob_b[1]=5;
	cmplx_mul(prob_a, prob_b, izlaz);
	printf("Množenje. Realni je %f, imaginarni je %f\n", izlaz[0], izlaz[1]);
	return 0;
}
