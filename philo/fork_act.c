/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:56:36 by myukang           #+#    #+#             */
/*   Updated: 2022/05/19 21:03:57 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"





void	pick_fork_rl(pthread_mutex_t *fork, int nth)
{
	pthread_mutex_lock(fork[nth], 
}

void	pick_fork_lr(pthread_mutex_t *fork, int nth)
{

}

void	pick_fork_up(pthread_mutex_t *fork, int nth)
{
	if (nth % 2 == 0)
		pick_fork_rl(fork, nth);
	else
		pick_fork_lr(fork, nth);
}


void	put_fork_down()
{


}
