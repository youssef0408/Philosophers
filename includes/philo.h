/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:28 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:24 by yothmani         ###   ########.fr       */
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
	int				philo_id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_meal_time;
	long long		start_time;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_meals_to_eat;
	int				stop;
	pthread_mutex_t	access;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_info;

int					arg_check(int argc, char **argv);
int					ft_atoi(const char *str);
int					init_table(t_info *info, char **argv);
int					init_philos(t_info *info);
long long			time_stamp(void);
void				sleep_until(t_info *info, int time);
void				print_action(t_info *info, int id, char *string);
void				philo_dine(t_philo *philo);
void				*philo_thread(void *void_philosopher);
void				philo_dine(t_philo *philo);
void				cleanup_and_exit(t_info *info, t_philo *philo);
int					start_dinner(t_info *info);
void				is_dead(t_info *info, t_philo *philo);
#endif
