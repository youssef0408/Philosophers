/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:59:06 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/16 14:49:54 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *voided)
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
		philo_dine(philo);
		print_action(*philo, "is sleeping");
		sleep_until(philo->info, philo->info->time_to_sleep);
		print_action(*philo, "is thinking");
	}
	return (philo);
}

bool	is_dead(t_info *info)
{
	int i;
	long check;
	int meals;

	i = -1;
	meals = 0;
	while (++i < info->nb_of_philos)
	{
		pthread_mutex_lock(&(info->access));
		meals = info->philos[i].eat_count;
		pthread_mutex_unlock(&(info->access));
		if (info->min_meals_to_eat != -1 && meals >= info->min_meals_to_eat)
			continue ;
		pthread_mutex_lock(&(info->access));
		check = time_stamp() - info->philos[i].last_meal_time;
		pthread_mutex_unlock(&(info->access));
		if (print_death(&info, i, check))
			return(true);
	}}

	void philo_dine(t_philo * philo)
	{
		pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
		print_action(philo->info, philo->philo_id, "has taken a fork");
		if (philo->info->nb_of_philos == 1)
			pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
		pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
		print_action(philo->info, philo->philo_id, "has taken a fork");
		print_action(philo->info, philo->philo_id, "is eating");
		pthread_mutex_lock(&(philo->info->access));
		philo->last_meal_time = time_stamp();
		pthread_mutex_unlock(&(philo->info->access));
		sleep_until(philo->info, philo->info->time_to_eat);
		pthread_mutex_lock(&philo->info->access);
		philo->eat_count++;
		pthread_mutex_unlock(&(philo->info->access));
		pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
		pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
	}

	int start_dinner(t_info *info)
	{
		int idx;
		pthread_t *threads;

		threads = malloc(sizeof(pthread_t) * info->nb_of_philos);
		if (!threads)
			return (1);
		idx = -1;
		while (++idx < info->nb_of_philos)
		{
			if (pthread_create(&threads[idx], NULL, philo_thread,
					&info->philos[idx]))
				return (1);
			usleep(50);
		}
		check_status(info);
		idx = -1;
		while (++idx < info->nb_of_philos)
		{
			if (pthread_join(threads[idx], NULL))
				return (1);
		}
		return (0);
	}
