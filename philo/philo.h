/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:01:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/18 22:17:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * stdio.h for : printf
 * stdlib.h for : malloc, free
 * unistd.h for : write, usleeep
 * string.h for : memset
 * sys/time.h for : gettimeofday
 * pthread.h for : pthread functions..
 * */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define THREAD_WAIT 1
# define THREAD_START 2
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define FAIL -1
# define SUCCESS 1
# define _NULL	0
typedef unsigned long t_size;

typedef struct	s_philo
{
	int		total_eat;
	time_t	last_eat;
	int		status;
}	t_philo;

typedef struct	s_philo_data
{
	int				ready_status;
	t_philo			*philos_lst;
	pthread_t		*tid_lst;
	pthread_mutex_t	*fork;
}	t_philo_data;

typedef struct	s_argv
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_argv;

int	print_err(int errnum);
//init_argv
int	init_argv(t_argv *argument, char **av);
int	ft_atoi(const char *str);
int	ac_err(int ac);
#endif
