/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:01:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 22:21:17 by myukang          ###   ########.fr       */
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

# define THREAD_STOP 1
# define THREAD_START 2
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define FAIL -1
# define SUCCESS 1
# define _NULL	0
typedef unsigned long t_size;
typedef int			t_status;

typedef struct	s_philo
{
	int				nth;
	int				total_eat;
	time_t			last_eat;
	t_status		status;
}	t_philo;

typedef struct	s_philo_data
{
	int				is_philo_thread_made;
	t_philo			*philos_lst;
	pthread_t		*tid_lst;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*philos_status; //philo->status 조정시 사용
}	t_philo_data;

typedef struct	s_argv
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_argv;

typedef struct	s_routine_param
{
	t_argv			argv;
	t_philo_data	*philo_data;
	t_philo			*philo;
}	t_routine_param;

int	print_err(int errnum);
//init_argv
int	init_argv(t_argv *argument, char **av);
int	ft_atoi(const char *str);
int	ac_err(int ac);
#endif
