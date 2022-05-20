/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:07:52 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:55:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

suseconds_t	cal_time(struct timeval created_t)
{
	struct timeval	cur_t;
	time_t			sec;
	suseconds_t		m_sec;

	gettimeofday(&cur_t, 0);
	sec = cur_t.tv_sec - created_t.tv_sec;
	m_sec = cur_t.tv_usec - created_t.tv_usec;
	m_sec += sec * 1000;
	return (m_sec);
}
