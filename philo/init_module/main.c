/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:12:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 04:51:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_argv			argv;
	t_philo_data	*philo_data;

	philo_data = 0;
	if (ac_err(ac) == FAIL)
		return (print_err(1));
	if (init_argv(&argv, av) == FAIL)
		return (print_err(2));
	if (init_philo_data(argv, &philo_data) == FAIL)
		return (print_err(3));
	if (init_mutex(argv, philo_data) == FAIL)
		return (print_err(3));
	if (init_reaper_thread(argv, philo_data) == FAIL)
		return (print_err(4));
	if (init_philo_thread(argv, philo_data) == FAIL)
		return (print_err(5));
	return (0);
}
