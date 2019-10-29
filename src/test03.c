#include <cmplx.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	cmplx_t proba;
	double izlaz;
	proba[0]=3;
	proba[1]=4;
	izlaz = cmplx_mag(proba);
	printf("Amplituda je %f\n", izlaz);
	return 0;
}
