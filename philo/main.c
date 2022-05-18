/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:12:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/18 22:17:19 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_argv			argument;
	t_philo_data	*philo_data;

	philo_data = 0;
	if (ac_err(ac) == FAIL)
		return (print_err(1));
	if (init_argv(&argument, av) == FAIL)
		return (print_err(2));
	if (philos_init(&philo_data, argument) == FAIL)
		return (print_err(3));
	return (0);
}
