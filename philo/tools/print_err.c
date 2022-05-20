/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:27:18 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:08:08 by myukang          ###   ########.fr       */
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
	if (errnum == 4)
		write(2, "", 1);
	if (errnum == 5)
		write(2, "", 1);
	return (FAIL);
}
