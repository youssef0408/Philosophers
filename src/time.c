/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/09 16:03:40 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long time_cmp(long long start_time, long long current_time)
{
    return(current_time - start_time);
}

long long	time_stamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	sleep_until(long long duration, t_info *info)
{
	long long	start_time;
    
	start_time = time_stamp();
	while (!(info->death))
	{
        if(time_cmp(start_time, time_stamp()) >= duration)
            break;
		usleep(500);
	}
}
