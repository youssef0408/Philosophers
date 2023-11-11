/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:17 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/09 16:29:42 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_dinner(t_info *info, char **argv)
{
	info->nb_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->full_satisfaction = 0;
	info->death = false;
	if (info->nb_of_philos < 2 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0)
		return (-1);
	if (argv[5])
	{
		info->min_meals_to_eat = ft_atoi(argv[5]);
		if (info->min_meals_to_eat < 1)
			return (-2);
	}
	else
		info->min_meals_to_eat = -1;
	if (init_forks(info) || init_philos(info))
		return (-3);
	return (0);
}

int	init_forks(t_info *info)
{
	int	idx;

	idx = -1;
	while (++idx < info->nb_of_philos)
	{
		if (pthread_mutex_init(&info->forks[idx], NULL))
			return (1);
	}
	return (0);
}

int	init_philos(t_info *info)
{
	int	idx;

	idx = -1;
	while (++idx < info->nb_of_philos)
	{
		info->philos[idx].philo_id = idx;
		info->philos[idx].eat_count = 0;
		info->philos[idx].left_fork = idx;
		info->philos[idx].right_fork = (idx + 1) % info->nb_of_philos;
		info->philos[idx].info = info;
	}
	return (0);
}

bool	is_dead(t_info *info, t_philo *philo)
{
	int i;

	while (!info->full_satisfaction)
	{
		i = -1;
		while (++i < info->nb_of_philos && !info->death)
		{
			pthread_mutex_lock(&(info->meal_check));
			if (time_cmp(philo[i].last_meal, time_stamp()) > info->time_to_die)
			{
				//print the action(died)
				info->death = true;
			}
			pthread_mutex_unlock(&(info->meal_check));
			usleep(500);
		}
		if (info->death)
			return (true);
		i = 0;
		while (info->min_meals_to_eat != -1 && info->nb_of_philos
			&& philo[i].eat_count >= info->min_meals_to_eat)
			i++;
		if (i == info->nb_of_philos)
			return (true);
	}
	return (false);
}