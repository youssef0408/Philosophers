/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:28 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/20 15:30:10 by yothmani         ###   ########.fr       */
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
	int				min_meals_required;
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
void				print_action(t_philo philo, char *string);
int					print_death(t_info **info, int i, long check_time);
int					philo_dine(t_philo *philo);
void				check_status(t_info *info);
int					start_dinner(t_info *info);
bool				all_finished_eating(t_info *info, int meals_eaten);
bool				is_meal_completion_valid(t_info *info);
bool				is_dead(t_info *info);
void				cleanup_and_destroy_mutex(t_info *table);
void				*philo_routine(void *voided);
#endif
