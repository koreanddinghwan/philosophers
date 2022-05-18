/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:46 by myukang           #+#    #+#             */
/*   Updated: 2022/05/18 17:19:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	validate_av_num(char **av)
{
	int	i;
	int	err;

	i = 1;
	while (av[i])
	{
		err = check_num(av[i]);
		if (err == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

void	init_struct(t_argv *argument, char **av)
{
	int	i;
	
	i = 1;
	argument->times_must_eat = -1;
	argument->num_of_philo = ft_atoi(av[i++]);
	argument->time_to_die = ft_atoi(av[i++]);
	argument->time_to_eat = ft_atoi(av[i++]);
	argument->time_to_sleep = ft_atoi(av[i++]);
	if (av[i])
		argument->times_must_eat = ft_atoi(av[i++]);
}

int	init_argv(t_argv *argument, char **av)
{
	if (FAIL == validate_av_num(av))
		return (FAIL);
	init_struct(argument, av);
	return (SUCCESS);
}
