/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:28 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/09 16:22:39 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_info	*info;
	int				philo_id;
	int				eat_count;
	int				right_fork;
	int				left_fork;
	pthread_t		thread_id;
	long long		last_meal;
}					t_philo;

typedef struct s_info
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				min_meals_to_eat;
	bool			death;
	int				full_satisfaction;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_check;
}					t_info;

int					arg_check(int argc, char **argv);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					init_dinner(t_info *info, char **argv);
int					init_forks(t_info *info);
int					init_philos(t_info *info);
long long			time_cmp(long long start_time, long long current_time);
long long			time_stamp(void);
void				sleep_until(long long duration, t_info *info);

#endif
