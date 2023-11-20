/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:59:06 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/20 15:14:33 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_dead(t_info *info)
{
	int		i;
	long	check;
	int		meals;

	i = -1;
	meals = 0;
	while (++i < info->nb_of_philos)
	{
		pthread_mutex_lock(&(info->access));
		meals = info->philos[i].eat_count;
		pthread_mutex_unlock(&(info->access));
		if (info->min_meals_required != -1 && meals >= info->min_meals_required)
			continue ;
		pthread_mutex_lock(&(info->access));
		check = time_stamp() - info->philos[i].last_meal_time;
		pthread_mutex_unlock(&(info->access));
		if (print_death(&info, i, check))
			return (true);
	}
	return (false);
}

void	check_status(t_info *info)
{
	while (true)
	{
		if (is_dead(info))
			return ;
		if (is_meal_completion_valid(info))
			return ;
	}
}

bool	all_finished_eating(t_info *info, int meals_eaten)
{
	if (!meals_eaten && info->min_meals_required != -1)
	{
		pthread_mutex_lock(&info->access);
		info->stop = true;
		pthread_mutex_unlock(&info->access);
		return (true);
	}
	return (false);
}

bool	is_meal_completion_valid(t_info *info)
{
	int	i;
	int	meals_eaten;
	int	meals;

	meals_eaten = 0;
	meals = 0;
	i = -1;
	while (++i < info->nb_of_philos)
	{
		pthread_mutex_lock(&info->access);
		meals = info->philos[i].eat_count;
		pthread_mutex_unlock(&info->access);
		if (info->min_meals_required != -1 && meals < info->min_meals_required
			+ 1)
		{
			meals_eaten = 1;
			break ;
		}
	}
	if (all_finished_eating(info, meals_eaten))
		return (true);
	return (false);
}
