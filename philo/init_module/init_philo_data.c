/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:40:50 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:55:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * alloc_philo_data => malloc philo_data and allocation NULL to pointers
 * init_fork => malloc fork mutex array
 * init_philos_arr => malloc philos array and initialize it
 * init_philo_tid => malloc thread id array
 * */

#include "philo.h"

t_status	init_philo_tid(t_argv argv, t_philo_data *philo_data)
{
	philo_data->tid_arr = malloc(sizeof(pthread_t) * argv.num_of_philo);
	if (!philo_data->tid_arr)
	{
		philo_free(argv, philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	init_philos_arr(t_argv argv, t_philo_data *philo_data)
{
	int		i;
	t_philo	*philos_arr;

	(philo_data)->philos_arr = malloc(sizeof(t_philo) * argv.num_of_philo);
	if (!(philo_data)->philos_arr)
	{
		philo_free(argv, philo_data);
		return (FAIL);
	}
	i = 0;
	philos_arr = (philo_data->philos_arr);
	while (i < argv.num_of_philo)
	{
		philos_arr[i].total_eat = 0;
		philos_arr[i].nth = i + 1;
		philos_arr[i].status = THREAD_WAIT;
		i++;
	}
	philo_data->philos_arr = philos_arr;
	return (SUCCESS);
}

t_status	init_fork(t_argv argv, t_philo_data *philo_data)
{
	philo_data->m_fork = malloc(sizeof(pthread_mutex_t) * (argv.num_of_philo));
	if (!philo_data->m_fork)
	{
		philo_free(argv, philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	alloc_philo_data(t_philo_data **philo_data)
{
	*philo_data = malloc(sizeof(t_philo_data) * 1);//philo_data동적할당
	if (!(*philo_data))
		return (FAIL);
	(*philo_data)->philos_arr = 0;
	(*philo_data)->tid_arr = 0;
	(*philo_data)->m_fork = 0;
	(*philo_data)->threads_status = THREAD_WAIT;
	return (SUCCESS);
}

t_status	init_philo_data(t_argv argv, t_philo_data **philo_data)
{
	if (alloc_philo_data(philo_data) == FAIL)//널가드
		return (FAIL);
	if (init_fork(argv, *philo_data) == FAIL)//fork 뮤텍스 리스트
		return (FAIL);
	if (init_philos_arr(argv, *philo_data) == FAIL)//philo_list담고, 
		return (FAIL);
	if (init_philo_tid(argv, *philo_data) == FAIL)
		return (FAIL);
	gettimeofday(&(*philo_data)->time_created, 0);
	return (SUCCESS);
}
