/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:12:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:21:19 by myukang          ###   ########.fr       */
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
	if (philos_init(argv, &philo_data) == FAIL)
		return (print_err(3));
	//사신쓰레드
	if (reaper_thread_init(argv, philo_data) == FAIL)
		return (print_err(4));
	if (philos_thread_init(argv, philo_data) == FAIL)
		return (print_err(5));
	//쓰레드들 스타또!
	return (0);
}
