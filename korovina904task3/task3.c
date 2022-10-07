#include "omp.h"
#include "stdio.h"

//Solving the problem, I assumed that a[0]=1.

int main (int argc, char* argv[])
{
//Declaration of variables, the size of the array a[N+1] is larger by one for the correct processing of the last element.
	int N = 100000, j, f, a[N+1];
	unsigned long long int b[N];
// Array initialization
	for (int i=0; i <= N+1; ++i)
	a[i]=i+1;
		
	b[0] = 0;
	
#pragma omp parallel private(j,f), shared(a,b)
	{	
//Sharing work between threads.	
#pragma omp for 
		
		for (int j=1; j <= N; ++j) 
		{
//Determining the element that is divisible by 3.
			f = j % 3; 
		
			if (f == 0)
			{
//Finding the element b[j] by the formula.
				b[j] = a[j-1]/3;
				b[j] = a[j]*b[j]*a[j+1];
			}
		
			if (f == 1) 
			{
				b[j] = a[j+1]/3;
				b[j] = a[j]*b[j]*a[j-1];
			}
		
			if (f == 2) 
			{
				b[j] = a[j]/3;
				b[j] = a[j+1]*b[j]*a[j-1];
			}
		}
	}
//The output of the final array.
	for (int i=1; i <= N; ++i)
//Be careful, it will output 100,000 lines :)
	printf("b[%d] = %lld\n", i, b[i]);
	return 0;
}