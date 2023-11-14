/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:28 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/14 15:58:21 by yothmani         ###   ########.fr       */
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
	long long		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal_check;
	t_philo			philos[250];
}					t_info;

int					arg_check(int argc, char **argv);
int					ft_atoi(const char *str);
int					init_dinner(t_info *info, char **argv);
int					init_forks(t_info *info);
int					init_philos(t_info *info);
long long			time_cmp(long long start_time, long long current_time);
long long			time_stamp(void);
void				sleep_until(long long duration, t_info *info);
void				print_action(t_info *info, int id, char *string);
void				philo_dine(t_philo *philo);
void				*philo_thread(void *void_philosopher);
void				philo_dine(t_philo *philo);
void				cleanup_and_exit(t_info *info, t_philo *philo);
int					thread_launch(t_info *info);
void				is_dead(t_info *info, t_philo *philo);
#endif
