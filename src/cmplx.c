#include <cmplx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159


void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
	c[0] = (a[0]*b[0] + a[1]*b[1])/(b[0]*b[0] + b[1]*b[1]);
	c[1] = (a[1]*b[0] - a[0]*b[1])/(b[0]*b[0] + b[1]*b[1]);
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
	c[0] = a[0]*b[0] - a[1]*b[1];
	c[1] = a[1]*b[0] + a[0]*b[1];
}

double cmplx_mag(cmplx_t a){
	return sqrt(a[0]*a[0] + a[1]*a[1]);
}

double cmplx_phs(cmplx_t a){
	return atan(a[1]/a[0]);
}

double cmplx_real(double mag, double phs){
	return mag*cos(phs);
}

double cmplx_imag(double mag, double phs){
	return mag*sin(phs);
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
	int i, j;
	cmplx_t pom;
	for (i=0; i<N; ++i){
		 output[i][0] = 0;
		 output[i][1] = 0;
		 for (j=0; j<N; j++){
		 	pom[0] = cos(2*PI*j*i/N);
			pom[1] = -1 * sin(2*PI*j*i/N);
			cmplx_mul(pom, input[j], pom);
			output[i][0] += pom[0];
			output[i][1] += pom[1];
		 }
		 output[i][0] = roundf(output[i][0] * 10000) / 10000;
		 output[i][1] = roundf(output[i][1] * 10000) / 10000;
		 output[i][0] = (output[i][0] == 0) ? 0 : output[i][0];
		 output[i][1] = (output[i][1] == 0) ? 0 : output[i][1];
	}
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
	int i, j;
	cmplx_t pom;
	for (i=0; i<N; ++i){
		 output[i][0] = 0;
		 output[i][1] = 0;
		 for (j=0; j<N; j++){
		 	pom[0] = cos(2*PI*j*i/N) / N;
			pom[1] = sin(2*PI*j*i/N) / N;
			cmplx_mul(pom, input[j], pom);
			output[i][0] += pom[0];
			output[i][1] += pom[1];
		 }
		 output[i][0] = roundf(output[i][0] * 10000) / 10000;
		 output[i][1] = roundf(output[i][1] * 10000) / 10000;
		 output[i][0] = (output[i][0] == 0) ? 0 : output[i][0];
		 output[i][1] = (output[i][1] == 0) ? 0 : output[i][1];
	}
}
