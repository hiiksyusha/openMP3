#include "omp.h"
#include "stdio.h"

//Matrices are always square and identical

int main (int argc, char* argv[]) {
	
//Array initialization	
 	int **a;
 	int **b;
 	int **c;
	int n = 4,j,i,k ;
	
 	a = (int**) malloc(n*sizeof(int*));
	c = (int**) malloc(n*sizeof(int*));
	b = (int**) malloc(n*sizeof(int*));
 	for (int i = 0; i < n; i++) {
 		a[i] = (int*) malloc(n*sizeof(int));
		b[i] = (int*) malloc(n*sizeof(int));
		c[i] = (int*) malloc(n*sizeof(int));
	}


//Filling the matrix with random values from -1000 to 1000
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
 			a[i][j] = -1000 + rand() % (1000 + 1000 + 1);
 			b[i][j] = -1000 + rand() % (1000 + 1000 + 1);
 			c[i][j] = 0;
 		}
 	}
	
//Beginning of the parallel area
#pragma omp parallel private(j,i,k), shared(a,b,c,n) 
	{

//Multiplication
#pragma omp for 
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < n; ++j) {
 			for (int k = 0; k < n; ++k) {
 				c[i][j] += a[i][k] * b[k][j];
 			}
 		}
 	}

//End parallel to the area
}
	
 	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf( "%d ", c[i][j]);
		}
		putchar( '\n' );
	}

//Releasing the memory
	for (int i = 0; i < n; i++) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	
	free(a);
	free(b);
	free(c);
    
    return 0;
}
	
	
	
