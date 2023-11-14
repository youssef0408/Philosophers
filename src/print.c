/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:01:00 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/14 15:27:51 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_info *info, int id, char *string)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->death))
		printf("%lli %i %s\n", time_stamp() - info->start_time, id + 1, string);
	pthread_mutex_unlock(&(info->print));
	return ;
}
