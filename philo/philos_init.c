/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:45:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:06:17 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	philo_tid_init(t_argv argv, t_philo_data *philo_data)
{
	philo_data->tid_lst = malloc(sizeof(pthread_t) * argv.num_of_philo);
	if (!philo_data->tid_lst)
	{
		free(philo_data->philos_status);
		free(philo_data->fork);
		free(philo_data->philos_lst);
		free(philo_data)
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	philo_list_init(t_argv argv, t_philo_data *philo_data)
{
	int		i;
	t_philo	*philos_lst;

	(philo_data)->philos_lst = malloc(sizeof(t_philo) * argv.num_of_philo);
	if (!(philo_data)->philo_lst)
	{
		free(philo_data->fork);
		free(philo_data);
		return (FAIL);
	}
	i = 0;
	philos_lst = (philo_data->philos_lst);
	while (i < argv.num_of_philo)
	{
		philos_lst[i].total_eat = 0;
		philos_lst[i].nth = i;
		philos_lst[i].status = THREAD_STOP;
		i++;
	}
	philo_data->philos_lst = philos_lst;
	return (SUCCESS);
}

t_status	fork_init(t_argv argv, t_philo_data *philo_data)
{
	int				i;
	pthread_mutex_t	*fork;

	philos_data->fork = malloc(sizeof(pthread_mutex_t) * (argv.num_of_philo));
	if (!fork)
	{
		free(philo_data);//널가드, philo_data 해제
		free(philo_data->philos_status);
		return (FAIL);
	}
	i = 0;
	fork = philo_data->fork;
	while (i < argv.num_of_philo)
	{
		if (pthread_mutex_init(fork + i, t_NULL) != 0)
		{
			free(philo_data->philos_status);
			free((philo_data)->fork);
			free(philo_data);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

t_status	philos_data_init(t_argv argv, t_philo_data **philo_data)
{
	int				i;
	pthread_mutex_t	*status;

	*philo_data = malloc(sizeof(t_philo_data) * 1);//philo_data동적할당
	if (!(*philo_data))
		return (FAIL);
	(*philo_data)->philos_status = malloc(sizeof(pthread_mutex_t) * argv.num_of_philo);//philos_status 동적할당
	if (!((*philo_data)->philos_status))
	{
		free(*philo_data);
		return (FAIL);
	}
	i = 0;
	status = (*philo_data)->philos_status;
	while (i < argv.num_of_philo)
	{
		if ((pthread_mutex_init(status + i, t_NULL) == FAIL))
		{
			free(*philo_data);
			free(status);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

t_status	philos_init(t_argv argv, t_philo_data **philo_data)
{
	if (philos_data_init(argv, *philo_data) == FAIL)//널가드
		return (FAIL);
	if (fork_init(argv, *philo_data) == FAIL)//fork 뮤텍스 리스트
		return (FAIL);
	if (philo_list_init(argv, *philo_data) == FAIL)//philo_list담고, 
		return (FAIL);
	if (philo_tid_init(argv, *philo_data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
