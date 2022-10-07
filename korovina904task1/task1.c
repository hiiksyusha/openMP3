#include "omp.h"
#include "stdio.h"

int main (int argc, char* argv[])
{
	#pragma omp parallel
	
	{		
			printf("Hello, World! I'm thread number %d\n", omp_get_thread_num()); 
			// Output greeting and thread number :)
	}
	
	return 0;
}
	
