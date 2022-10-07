#include "omp.h"
#include "stdio.h"

int main (int argc, char* argv[])
{
	int N = 1000, private_sum, global_sum = 0, i;
	// We initialize the variables N, the sum for a single thread, and the sum of all sums.
	
#pragma omp parallel private(i, private_sum) shared(global_sum)
	// We select a parallel region and set private and public variables.
	{ 
		private_sum = 0;
#pragma omp for
		for (int i=1; i <= N; i =i+1)
	//Loop for to find the sum.
		{
			private_sum = private_sum+i;
		}
#pragma omp critical
	// Critical region for avoiding errors in the work of threads.
	// printf("I'm thread number %d\n my sum: %d\n", omp_get_thread_num(), private_sum);
	// Amount for each stream.
		global_sum += private_sum;
	// Total amount.
	}
printf("Global sum: %d\n", global_sum);
return 0;
}