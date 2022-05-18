#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *runner(void *param)
{
	printf("Im thread!\n");
	pthread_exit(0);
}

int main(int ac, char **av)
{
	pid_t	pid;
	pthread_t	tid;

	printf("A  = %d\n", getpid());
	pid = fork();
	if (pid > 0)//부모1
	{
		wait(NULL);
		printf("B = %d\n", pid);
	}
	if (pid == 0)//자식1
	{
		pid = fork();
		if (pid > 0)//자식1 == 부모2
		{
			wait(NULL);
			printf("c = %d\n", pid);
		}
		pthread_create(&tid, NULL, runner, NULL);//자식1 - 자식2
	}
	pid = fork();
	if(pid > 0)
	{
		wait(NULL);
		printf("D = %d\n", pid);
	}
	return 0;
}
