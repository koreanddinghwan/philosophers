/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:21:48 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 03:28:02 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_time(t_philo_data *philo_data, struct timeval	created_t, struct timeval	cur_t)
{
	pthread_mutex_lock(m_writing);
	printf("passed time : s :%d, ms: %d\n", cur_t.tv_sec - created_t.tv_sec, cur_t.tv_usec - created_t.tv_usec);
	pthread_mutex_unlock(m_writing);
}
