/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:53:22 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 21:55:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_philo_data *philo_data)
{
	free(philo_data->philos_lst);
	free(philo_data->tid_lst);
	free(philo_data->fork);
	free(philo_data->philos_status);
	free(philo_data);
}
