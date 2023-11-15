/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:17 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/15 15:07:58 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_info *info)
{
	int	idx;
	long long start_time;

	idx = 0;
	start_time = time_stamp();
	while (idx < info->nb_of_philos)
	{
		if(pthread_mutex_init(&info->forks[idx], NULL))
			return(1);
		info->philos[idx].philo_id = idx + 1;
		info->philos[idx].left_fork = idx;
		info->philos[idx].right_fork = (idx + 1) % info->nb_of_philos;
		info->philos[idx].eat_count = 0;
		info->philos[idx].last_meal_time = time_stamp();
		info->philos[idx].start_time = start_time;
		info->philos[idx].info = info;
		idx++;
	}
	return (0);
}

int	init_table(t_info *info, char **argv)
{
	info->nb_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->min_meals_to_eat = -1;
	info->stop = 0;
	if (argv[5])
		info->min_meals_to_eat = ft_atoi(argv[5]);
	info->philos = malloc(sizeof(t_philo) * info->nb_of_philos);
	info->forks =  malloc(sizeof(pthread_mutex_t) * info->nb_of_philos);
	if(!info->philos || !info->forks)
		return (-1);
	if(pthread_mutex_init(&(info->access), NULL))
		return(-1);
	if (init_philos(info))
		return (-3);
	return (0);
}
