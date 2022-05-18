/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:45:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/18 22:17:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_creation(t_philo_data *philo_data, int i)
{
	int	rtn;

	rtn = pthread_create((philo_data->tid_lst)[i], 0, routine, philo_data);
	if (rtn != 0)
	{
		free(philo_data->tid_lst);
		return (FAIL);
	}
	return (SUCCESS);
}

int	thread_join()
{

}

int	philo_thread_init(t_argv argv, t_philo_data *philo_data)
{
	int	i;

	philo_data->tid_lst = malloc(sizeof(pthread_t) * argv.num_of_philo);
	if (!philo_data->tid_lst)
		return (FAIL);
	i = 0;
	while (i < argv.num_of_philo)
	{
		if (thread_creation(philo_data) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	fork_init(t_argv argv, t_philo_data *philo_data)
{
	int	i;

	philo_data->fork = malloc(sizeof(pthread_mutex_t) * (argv.num_of_philo));
	if (!philo_data->fork)
		return (FAIL);
	return (SUCCESS);
}

int	philos_init(t_argv argv, t_philo_data **philo_data)
{
	*philo_data = malloc(sizeof(t_philo_data) * 1);
	if (!(*philo_data))
		return (FAIL);
	/* 
	 * philo_lst init해야함.
	 * s_philos를 argv.num_of_philo만큼 생성, 
	 * 각 쓰레드는 멈춰있는 상태
	 * 각 철학자는 status를 가지고있음
	 * 처음 만들어진 상태, thread로 루틴이 돌지 않는 상태에선
	 * THREAD_WAIT으로 status줘야함.
	 * */
	/*
	 * philo_lst가 init되고나선
	 * 독립적으로 철학자들이 죽었는지 살았는지 확인하는
	 * philo_checker라는 쓰레드를 만들어야한다.
	 *
	 * */
	if (fork_init(argv, *philo_data) == FAIL)
	{
		free(*philo_data);
		return (FAIL);
	}
	if (philo_thread_init(argv, *philo_data) == FAIL)
	{
		free(*philo_data);
		free(philo_data->fork);
		return (FAIL);
	}
	return (SUCCESS);
}
