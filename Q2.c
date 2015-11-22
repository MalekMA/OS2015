#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	int num_in;
	printf("Please enter the amount of threads to use: ");
	scanf("%d", &num_in);

	int n = 100000000;
	float x; 
	float y[100000000];
	float dx = 1 / (n + 1);

	#ifdef _OPENMP
	omp_set_num_threads(num_in);
	#endif

	#pragma omp parallel for private(x)
		for(int i = 0; i < n; i++)
			#pragma omp critical 
				x = i * dx;
				y[i] = exp(x) * sin(x) * sqrt( 5 * x + 6);
				printf(" x is %f and y at %d is %f\n", x, i, y[i]);
		}
}
