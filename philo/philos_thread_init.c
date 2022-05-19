/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_thread_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:02:11 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:21:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	thread_creation(t_argv argv, t_philo_data *philo_data, int i)
{
	t_routine_param	param;
	
	param.argv = argv;
	param.philo_data = philo_data;
	param.philo = (philo_data->philos_lst)[i];
	if (pthread_create((philo_data->tid_lst)[i], 0, routine, param) == FAIL)
	{
		philo_free(philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}

t_status	philo_thread_init(t_argv argv, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while (i < argv.num_of_philo)
	{
		if (thread_creation(argv, philo_data, i) == FAIL)
		{
			philo_free(philo_data);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
