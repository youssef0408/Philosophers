/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:28 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/06 15:50:33 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_info		*info;
	int					philo_id;
	int					eat_count;
	p_thread_mutex_t	*right_fork;
	p_thread_mutex_t	*left_fork;
}						t_philo;

typedef struct s_info
{
	int					nb_of_philos;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					must_eat;
	int					death;
	int					full_satisfaction;
	t_philo				*philos;
	p_thread_mutex_t	*forks;
	p_thread_mutex_t	*meal_check;
}						t_info;

int						arg_check(int argc, char **argv);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
int						init_dinner(t_info *info, char **argv);

e-cala
tterribi

#endif
