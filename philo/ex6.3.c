#include <stdio.h>
#include <pthread.h>

# define true 1
# define false 0

int sum;
int turn;
int flag[2];

void	*producer()
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		flag[0] = true;
		turn = 1;
		while (flag[1] && turn == 1)
			;

		sum++;
		flag[0] = false;
		i++;
	}
	pthread_exit(0);
}


void	*consumer()
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		flag[1] = true;
		turn = 0;
		while (flag[0] && turn == 0)
			;

		sum++;
		flag[1] = false;
		i++;
	}
	pthread_exit(0);
}

int main()
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, 0, producer, 0);
	pthread_create(&t2, 0, consumer, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	printf("sum : %d\n", sum);
}
