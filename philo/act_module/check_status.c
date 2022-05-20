/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 05:06:01 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 05:35:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * curtime - lasteat check,
 * if mininum eat, check
 * if status should be dead, change status of philo_data thread_status and
 * each status
 * */

#include "philo.h"

t_status	check_status(t_philo_data *philo_data, t_philo *philo)
{
	pthread_mutex_lock(&(philo_data->m_thread_status));
	if ()
		return (DEAD)
	
}
