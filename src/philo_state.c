/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:59:06 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/14 15:52:59 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *void_philosopher)
{
	int		i;
	t_philo	*philo;
	t_info	*info;

	i = 0;
	philo = (t_philo *)void_philosopher;
	info = philo->info;
	if (philo->philo_id % 2)
		usleep(15000);
	while (!(info->death))
	{
		philo_dine(philo);
		if (info->full_satisfaction)
			break ;
		print_action(info, philo->philo_id, "is sleeping");
		sleep_until(info->time_to_sleep, info);
		print_action(info, philo->philo_id, "is thinking");
		i++;
	}
	return (NULL);
}

void	is_dead(t_info *info, t_philo *philo)
{
	int	i;

	while (!info->full_satisfaction)
	{
		i = -1;
		while (++i < info->nb_of_philos && !info->death)
		{
			pthread_mutex_lock(&(info->meal_check));
			if (time_cmp(philo[i].last_meal, time_stamp()) > info->time_to_die)
			{
				print_action(info, i, "died");
				info->death = true;
			}
			pthread_mutex_unlock(&(info->meal_check));
			usleep(100);
		}
		if (info->death)
			break;
		i = 0;
		while (info->min_meals_to_eat != -1 && info->nb_of_philos
			&& philo[i].eat_count >= info->min_meals_to_eat)
			i++;
		if (i == info->nb_of_philos)
			info->full_satisfaction = 1;
	}
}

void	philo_dine(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->forks[philo->left_fork]));
	print_action(info, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(info->forks[philo->right_fork]));
	print_action(info, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(info->meal_check));
	print_action(info, philo->philo_id, "is eating");
	philo->last_meal = time_stamp();
	pthread_mutex_unlock(&(info->meal_check));
	sleep_until(info->time_to_eat, info);
	philo->eat_count++;
	pthread_mutex_unlock(&(info->forks[philo->left_fork]));
	pthread_mutex_unlock(&(info->forks[philo->right_fork]));
}

void    cleanup_and_exit(t_info *info, t_philo *philo)
{
    int idx;

    idx = -1;
    while(++idx < info->nb_of_philos)
        pthread_join(philo[idx].thread_id, NULL);
    idx = -1;
    while (++idx < info->nb_of_philos)
        pthread_mutex_destroy(&(info->forks[idx]));
    pthread_mutex_destroy(&(info->print));    
}

int	thread_launch(t_info *info)
{
	int idx;
	t_philo *philo;

	idx = 0;
	philo = info->philos;
	while (idx < info->nb_of_philos)
	{
		if (pthread_create(&(philo[idx].thread_id), NULL, philo_thread,
				(void *)&(philo[idx])))
			return (1);
		philo[idx].last_meal = time_stamp();
		idx++;
	}
	is_dead(info, info->philos);
	cleanup_and_exit(info, philo);
	return (0);
}
