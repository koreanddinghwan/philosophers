#include <pthread.h>
#include <stdio.h>

int sum;


void	*run1()
{
	int	i;

	i = 0;
	printf("This is run1\n");
	while (i < 10000000)
	{
		sum++;
		i++;
	}
	printf("%d\n", sum);
	pthread_exit(0);
}

void	*run2()
{
	int	i;

	i = 0;
	printf("THis is run2\n");
	while (i < 10000000)
	{
		i++;
		sum++;
	}
	pthread_exit(0);
}


int main()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, 0, run1, 0);
	pthread_create(&tid2, 0, run2, 0);
	pthread_join(tid1, 0);
	pthread_join(tid2, 0);
	printf("%d\n", sum);
	return 0;
}
