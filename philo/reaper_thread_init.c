/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_thread_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:08:36 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:21:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*reaper_routine(void *param)
{
	int	i;
	int	status;

	i = 0;
	while (1)
	{
		
	}
}

t_status	reaper_thread_init(t_argv argv, t_philo_data *philo_data)
{
	t_routine_param	param;
	pthread_t		reaper_tid;

	param.argv = argv;
	param.philo_data = philo_data;
	param.philo = _NULL;
	if (pthread_create(&reaper_tid, 0, reaper_routine, param) == FAIL)
	{
		philo_free(philo_data);
		return (FAIL);
	}
	return (SUCCESS);
}
