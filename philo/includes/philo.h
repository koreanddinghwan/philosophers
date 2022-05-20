/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:01:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/21 05:09:44 by myukang          ###   ########.fr       */
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

# define LOG_FORK 1
# define LOG_EATING 2
# define LOG_SLEEPING 3
# define LOG_THINKING 4
# define LOG_DEAD 5

# define FAIL 1
# define SUCCESS 0
# define _NULL	0
# define THREAD_WAIT 0
# define THREAD_START 1
# define THREAD_STOP 2 //some philosopher dead
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define FORK_ON_HAND 0
# define FORK_ON_TABLE 1

typedef unsigned long t_size;
typedef int			t_status;

typedef struct	s_philo
{
	int				nth;
	int				total_eat;
	time_t			last_eat;
	t_status		status;
	struct timeval	last_eat;
}	t_philo;

typedef struct	s_philo_data
{
	t_philo			*philos_arr;
	pthread_t		*tid_arr;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_writing; //philo->status 조정시 사용
	pthread_mutex_t	m_thread_status;
	t_status		threads_status;
	struct timeval	time_created;
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


int			ac_err(int ac);
int			print_err(int errnum);
int			init_argv(t_argv *argument, char **av);
t_status	init_philo_data(t_argv argv, t_philo_data **philo_data);
t_status	init_mutex(t_argv argv, t_philo_data *philo_data);
t_status	init_philo_data(t_argv argv, t_philo_data **philo_data);
t_status	init_philo_thread(t_argv argv, t_philo_data *philo_data);
t_status	init_reaper_thread(t_argv argv, t_philo_data *philo_data);


void		*routine_philo(void *param);
t_status	pick_fork(t_argv argv, t_philo_data *philo_data, t_philo *philo);
suseconds_t	cal_time(struct timeval created_t);
int			ft_atoi(const char *str);
void		philo_free(t_argv argv, t_philo_data *philo_data);
void		mutex_n_destroy(pthread_mutex_t	*mutex_arr, int n);
void		mutex_destroy_all(t_argv argv, t_philo_data *philo_data);
void		print_log(t_philo_data *philo_data, t_philo *philo, t_status log_type);

#endif
