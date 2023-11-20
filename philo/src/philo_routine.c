/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:13:11 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/20 15:17:25 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *voided)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)voided;
	print_action(*philo, "is thinking");
	stop = 1;
	while (stop)
	{
		pthread_mutex_lock(&philo->info->access);
		stop = !philo->info->stop;
		pthread_mutex_unlock(&philo->info->access);
		if (philo_dine(philo))
			return (NULL);
		print_action(*philo, "is sleeping");
		sleep_until(philo->info, philo->info->time_to_sleep);
		print_action(*philo, "is thinking");
	}
	return (philo);
}

int	philo_dine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
	print_action(*philo, "has taken a fork");
	if (philo->info->nb_of_philos == 1)
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
		return (1);
	}
	pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
	print_action(*philo, "has taken a fork");
	print_action(*philo, "is eating");
	pthread_mutex_lock(&(philo->info->access));
	philo->last_meal_time = time_stamp();
	pthread_mutex_unlock(&(philo->info->access));
	sleep_until(philo->info, philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->access);
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->info->access));
	pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
	return (0);
}

int	start_dinner(t_info *info)
{
	int			idx;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * info->nb_of_philos);
	if (!threads)
		return (1);
	idx = -1;
	while (++idx < info->nb_of_philos)
	{
		if (pthread_create(&threads[idx], NULL, philo_routine,
				&info->philos[idx]))
			return (free(threads), 1);
		usleep(50);
	}
	check_status(info);
	idx = -1;
	while (++idx < info->nb_of_philos)
	{
		if (pthread_join(threads[idx], NULL))
			return (free(threads), 1);
	}
	free(threads);
	return (0);
}
