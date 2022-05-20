/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:00:23 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:24:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo_data *philo_data, t_philo *philo, t_status log_type)
{
	if (log_type == LOG_FORK)
	{
		pthread_mutex_lock(philo_data->m_writing);
		printf("%d_in_ms %d has taken a fork\n", cal_time(philo_data->time_created, philo->nth);
		pthread_mutex_unlock(philo_data->m_writing);
	}
}
