/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:49:11 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:52:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * init_fork_mutex => init mutex each of fork
 * 					  if failed while mutex_init;
 * 					  	destroy all mutexes that were ok
 *
 * init_writing_mutex => init mutex for writing
 * 						 we need write mutex when print a message in terminal
 * 						 when a thread printing in terminal; 
 * 						 	no other threads should not print message in term
 * 
 * init_thread_status_mutex => init status mutex
 * 								if a thread died when a philosopher dead;
 * 									reaper thread will catch it and all thread 
 * 									should stop their act
 * 							
 * 
 * */

#include "philo.h"

t_status	init_thread_status_mutex(t_argv argv, t_philo_data *philo_data)
{
	pthread_mutex_t	*m_thread_status;

	m_thread_status = &(philo_data->m_thread_status);
	if (pthread_mutex_init(m_thread_status, _NULL) != 0)
	{
		mutex_n_destroy(philo_data->m_fork, argv.num_of_philo);
		pthread_mutex_destroy(&(philo_data->m_writing));
		philo_free(argv, philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	init_writing_mutex(t_argv argv, t_philo_data *philo_data)
{
	pthread_mutex_t	*m_writing;

	m_writing = &(philo_data->m_writing);
	if ((pthread_mutex_init(m_writing, _NULL) == FAIL))
	{
		mutex_n_destroy(philo_data->m_fork, argv.num_of_philo);
		philo_free(argv, philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	init_fork_mutex(t_argv argv, t_philo_data *philo_data)
{
	pthread_mutex_t	*m_fork;
	int				i;

	m_fork = philo_data->m_fork;
	i = 0;
	while (i < argv.num_of_philo)
	{
		if (pthread_mutex_init(&(m_fork[i]), _NULL) != 0)
		{
			mutex_n_destroy(philo_data->m_fork, i);
			philo_free(argv, philo_data);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

t_status	init_mutex(t_argv argv, t_philo_data *philo_data)
{
	if (init_fork_mutex(argv, philo_data) == FAIL)
		return (FAIL);
	if ((init_writing_mutex(argv, philo_data)) == FAIL)
		return (FAIL);
	if (init_thread_status_mutex(argv, philo_data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
