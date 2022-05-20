/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:37:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 05:10:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_activity(t_routine_param *param)
{
	t_philo_data	*philo_data;
	t_argv			argv;
	t_philo			*philo;

	philo_data = param->philo_data;
	argv = param->argv;
	philo = param->philo;
	while (1)
	{
		if (pick_fork(argv, philo_data, philo) == FAIL)
			break ;
		/*
		if (eating(argv, philo_data, philo) == FAIL)
			break ;
		if (sleeping(argv, philo_data, philo) == FAIL)
			break ;
		if (thinking(argv, philo_data, philo) == FAIL)
			break ;
		if (put_fork(argv, philo_data, philo) == FAIL)
			break ;
			*/
	}
}

void	*routine_philo(void *param)
{
	t_philo_data	*philo_data;
	t_philo			*philo;

	philo_data = ((t_routine_param *)param)->philo_data;
	philo = ((t_routine_param *)param)->philo;
	gettimeofday(&(philo->last_eat));
	philo_activity((t_routine_param *)param);
}
