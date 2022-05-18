#include <stdio.h>
#include <pthread.h>

int sum = 0;

pthread_mutex_t mutex[5];

void	*counter(void *param)
{
	int k;

	k = 0;
	while (k < 10000000)
	{
		pthread_mutex_lock(&mutex);
		sum++;
		k++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t	t1;
	pthread_t	t2;
	int	i;

	i = 0;
	while (i < 5)
	{
		pthread_mutex_init(&(mutex[i++]), NULL);
	}
	pthread_create(&t1, 0, counter, 0);
	pthread_create(&t2, 0, counter, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	printf("%d\n", sum);
	return 0;
}
