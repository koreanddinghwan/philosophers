/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:10:34 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 05:29:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork_l(t_philo_data *philo_data, t_philo *philo)
{
	pthread_mutex_lock(&(philo_data->m_fork)[philo->nth - 1]);
	print_log(philo_data, philo, LOG_FORK);
	pthread_mutex_unlock(&(philo_data->m_fork)[philo->nth - 1]);
}


void	pick_fork_r(t_argv argv, t_philo_data *philo_data, t_philo *philo)
{
	if (philo->nth == 1)
	{
		pthread_mutex_lock(&(philo_data->m_fork)[argv.num_of_philo - 1]);
		print_log(philo_data, philo, LOG_FORK);
		pthread_mutex_unlock(&(philo_data->m_fork)[argv.num_of_philo - 1]);
	}
	else
	{
		pthread_mutex_lock(&(philo_data->m_fork)[philo->nth - 2]);
		print_log(philo_data, philo, LOG_FORK);
		pthread_mutex_unlock(&(philo_data->m_fork)[philo->nth - 2]);
	}

}

t_status	pick_fork(t_argv argv, t_philo_data *philo_data, t_philo *philo)
{
	if (check_status(philo_data, philo) == DEAD)
		return (FAIL);
	if (philo->nth % 2 == 0)
	{
		pick_fork_r(argv, philo_data, philo);
		if (check_status(philo_data, philo) == DEAD)
			return (FAIL);
		pick_fork_l(philo_data, philo);
	}
	else
	{
		pick_fork_l(philo_data, philo);
		if (check_status(philo_data, philo) == DEAD)
			return (FAIL);
		pick_fork_r(argv, philo_data, philo);
	}
	return (SUCCESS);
}
