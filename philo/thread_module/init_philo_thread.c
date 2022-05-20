/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:02:11 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:57:15 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * init_philo_thread => create threads for philosophers
 * 
 * */


#include "philo.h"

t_status	create_philo_thread(t_argv argv, t_philo_data *philo_data, int i)
{
	t_routine_param	param;
	
	param.argv = argv;
	param.philo_data = philo_data;
	param.philo = philo_data->philos_arr + i;
	if (pthread_create(&(philo_data->tid_arr)[i], 0, routine_philo, &param) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

t_status	init_philo_thread(t_argv argv, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while (i < argv.num_of_philo)
	{
		if (create_philo_thread(argv, philo_data, i) == FAIL)
		{
			mutex_destroy_all(argv, philo_data);
			philo_free(argv, philo_data);
			//end threads for i threads
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
