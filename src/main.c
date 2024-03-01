/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:09:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/21 17:26:15 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (arg_check(argc, argv))
		return (1);
	if (init_table(&info, argv))
		return (1);
	if (start_dinner(&info))
	{
		print_error("Threads creation failed");
		return (1);
	}
	cleanup_and_destroy_mutex(&info);
	return (0);
}
