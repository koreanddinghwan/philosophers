#include <stdio.h>

int main(int ac, char **av)
{
	#pragma omp parallel
	{
		printf("I am a parallel region.\n");
	}
	return 0;
}

