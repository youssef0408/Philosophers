/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/20 21:27:37 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	time_stamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	sleep_until(t_info *info, int time)
{
	long long	current_time;
	int			stop;

	stop = 1;
	current_time = time_stamp();
	while (stop)
	{
		pthread_mutex_lock(&info->access);
		stop = !info->stop;
		pthread_mutex_unlock(&info->access);
		if (time_stamp() - current_time >= time)
			break ;
		usleep(100);
	}
}
