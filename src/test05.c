#include <cmplx.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	double amp;
	double faza;
	double real;
	amp = 5;
	faza = 3.14159;
	real = cmplx_real(amp, faza);
	printf("Realni dio proizasao iz amplitude i faze je %f\n", real);
	return 0;
}
