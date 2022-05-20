/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:53:22 by myukang           #+#    #+#             */
/*   Updated: 2022/05/20 16:00:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_argv argv, t_philo_data *philo_data)
{
	if (philo_data->philos_arr)
		free(philo_data->philos_arr);
	if (philo_data->tid_arr)
		free(philo_data->tid_arr);
	if (philo_data->m_fork)
		free(philo_data->m_fork);
	free(philo_data);
}

void	mutex_n_destroy(pthread_mutex_t	*mutex_arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&(mutex_arr[i]));
		i++;
	}
}


void	mutex_destroy_all(t_argv argv, t_philo_data *philo_data)
{
	mutex_n_destroy(philo_data->m_fork, argv.num_of_philo);
	pthread_mutex_destroy(&(philo_data->m_philos_status));
	pthread_mutex_destroy(&(philo_data->m_writng));
}
