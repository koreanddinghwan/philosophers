#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int value = 0;
void *runner(void *param)
{
	value = 5;
	pthread_exit(0);
}

int main(int ac, char **av)
{
	pid_t			pid;
	pthread_t		tid;
	pthread_attr_t	attr;

	pid = fork();

	if (pid == 0)
	{//부모프로세스의 메모리를 모두 복사
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, NULL);//자식프로세스의 쓰레드의 value 5로 수정됨
		pthread_join(tid, NULL);//쓰레드 종료까지 기다림
		printf("CHILD : value = %d\n", value);
	}
	else if (pid >  0)
	{
		wait(NULL);
		printf("parent : value = %d\n" , value);//main쓰레드에서는 value값 그대로임
	}
}
