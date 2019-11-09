#include <cmplx.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	double amp;
	double faza;
	double img;
	amp = 5;
	faza = 3.14159;
	img = cmplx_imag(amp, faza);
	printf("Imaginarni dio proizasao iz amplitude i faze je %f\n", img);
	return 0;
}
