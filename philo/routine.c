/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:32:18 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:21:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *param)
{
	t_philo_data	*philo_data;
	t_philo			*philo;

	philo_data = (t_routine_param)param->philo_data;
	philo = (t_routine_param *)param->philo;
	//status가 THREAD_STOP이면 블락
	pthread_mutex_lock(philo->status);
	while (philo->status == THREAD_STOP)
		;
	phthread_mutex_unlock(philo->status);
	//
	while ()
	{
		//pickup fork if i % 2 == 0 lr
		//or rl
		pick_fork_up(philo_data->fork, philo->nth, param);
		//if fork is not available, wait 
		//
		//
		//
		//eating for (philo_data -> time_to_eat)
		//
		//putdown_fork
		put_fork_down();
		//sleeping for (philo_data->time_to_sleep)
		//
		//
		//
	}
	phthread_mutex_unlock(philo_data->status);
}
