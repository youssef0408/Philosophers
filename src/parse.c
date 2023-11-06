/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:17 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/06 14:09:19 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int arg_check(int argc, char**argv)
{    
    int i;
    
    i = 1;
    if(argc < 5 || argc > 6)
        return(-1);
    while(i > 0 || i < 6)
    {
        if(ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i] > INT32_MAX))
            return(-2);
        i++;       
    }
    
    return(0);
}
int init_dinner(t_info *info, char **argv)
{
    info->nb_of_philos = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    info->full_satisfaction = 0;
    info->death = 0;
    if(info->nb_of_philos < 2 || info->time_to_die < 0
        || info->time_to_eat < 0 || info->time_to_sleep < 0)
        return(-1);
    if(argv[5])
    {
        info->must_eat = ft_atoi(argv[5]);
        if(info->must_eat < 1)
            return(-2);
    }
    if(init_forks(info) || init_philos(info))
        return(-3);
    return(0);
}

int init_forks(t_info *info)
{
    int idx;
    
    idx = -1;
    while(++idx < info->nb_of_philos)
    {
        if(pthread_mutex_init(&info->forks[idx], NULL))
            return(1);
    }
    return(0);
}

int init_philos(t_info *info)
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
    return(0);
}

