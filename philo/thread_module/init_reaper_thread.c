/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reaper_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:08:36 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 05:33:47 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * reaper_thread => check whether philosopher's thread is dead or not
 *
 * if a thread is dead, reaper thread should make all threads exit
 * to protect race condition to access philosopher's status
 * we should lock thread_status so that other threads can not use its data
 * of courese, philosopher threads will use status mutex lock and
 * so if its status is changed, they will change its status and break philo_routine
 * */


#include "philo.h"

t_status	get_status(t_argv argv, t_philo_data *philo_data)
{
	int		i;
	t_philo	philosopher;

	i = 0;
	while (i < argv.num_of_philo)
	{
		pthread_mutex_lock(&(philo_data->m_thread_status));
		philosopher = (philo_data->philos_arr)[i];
		if (philosopher.status == DEAD)
			return (FAIL);
		pthread_mutex_unlock(&(philo_data->m_thread_status));
		i++;
	}
	return (SUCCESS);
}

void	*reaper_routine(void *param)
{
	t_argv			argv;
	t_philo_data	*philo_data;

	argv = ((t_routine_param *)param)->argv;
	philo_data = ((t_routine_param *)param)->philo_data;
	while (1)
	{
		if (get_status(argv, philo_data) == DEAD)
			break ;
	}
	return (0);
}


t_status	init_reaper_thread(t_argv argv, t_philo_data *philo_data)
{
	t_routine_param	param;
	pthread_t		reaper_tid;

	param.argv = argv;
	param.philo_data = philo_data;
	param.philo = _NULL;
	if (pthread_create(&reaper_tid, 0, reaper_routine, &param) == FAIL)
	{
		mutex_destroy_all(argv, philo_data);
		philo_free(argv, philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}
