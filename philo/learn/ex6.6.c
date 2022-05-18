#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int sum = 0;

sem_t sem;


void *counter(void *param)
{
	int k;

	k = 0;
	while (k < 100000)
	{
		sem_wait(&sem);
		sum++;
		sem_post(&sem);
		k++;
	}
	pthread_exit(0);
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;

	sem_open(&sem, 0, 1);
	pthread_create(&tid1, NULL, counter, NULL);
	pthread_create(&tid2, NULL, counter, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("SUM : %d\n", sum);

}
