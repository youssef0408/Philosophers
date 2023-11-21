/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:01:00 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/21 17:25:39 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo philo, char *string)
{
	pthread_mutex_lock(&philo.info->access);
	if (!(philo.info->stop))
		printf("%lli %i %s\n", (time_stamp() - philo.start_time),
			philo.philo_id, string);
	pthread_mutex_unlock(&philo.info->access);
}

int	print_death(t_info **info, int i, long check_time)
{
	if (check_time > (*info)->time_to_die)
	{
		pthread_mutex_lock(&(*info)->access);
		printf("%lld %d %s\n", time_stamp() - (*info)->philos[i].start_time,
			(*info)->philos[i].philo_id, "\033[0;31mdied\033[0m");
		(*info)->stop = true;
		pthread_mutex_unlock(&(*info)->access);
		return (1);
	}
	return (0);
}

void	print_error(char *msg)
{
	printf("\033[0;31mError:\033[0m %s\n", msg);
}
