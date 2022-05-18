/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:27:18 by myukang           #+#    #+#             */
/*   Updated: 2022/05/18 22:17:19 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ac_err(int ac)
{
	if (av < 5 || ac > 6)
		return (FAIL);
	else
		return (SUCCESS);
}

int	print_err(int errnum)
{
	if (errnum == 1)
		write(2, "Check num of arguments\n", 23);
	if (errnum == 2)
		write(2, "Unavailable arguments\n", 23);
	if (errnum == 3)
		write(2, "philos_init_failed\n", 20);
	return (FAIL);
}
