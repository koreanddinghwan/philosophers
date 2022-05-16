/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:12:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/16 15:10:58 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int sum;
void *runner(void *param)
{
	int	i;
	int upper;

	printf("runner called\n");
	upper = atoi(param);
	sum = 0;
	i  = 1;
	while (i <= upper)
	{
		sum += i++;
	}
	pthread_exit(0);
}

int main(int ac, char **av)
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, av[1]);
	pthread_join(tid, NULL);

	printf("sum =  %d\n", sum);
	return (0);
}
