/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:40:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/13 15:05:56 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	arg_check(int argc, char **argv)
{
	int		i;
	int 	arg_value;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("\033[0mError: Invalid number of arguments. Expected 5 or 6 arguments.\n");
		return (-1);
	}
	while (i < argc)
	{
		arg_value = ft_atoi(argv[i]);
		if (arg_value <= 0 || arg_value > INT32_MAX)
		{
			printf("\033[0mError: Argument %d is not a valid positive 32-bit integer.\n", i);
			return (-1);
		}
		i++;
	}
	return (0);
}
