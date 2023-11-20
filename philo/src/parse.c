/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:40:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/20 15:33:33 by yothmani         ###   ########.fr       */
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

int	ft_isallnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (1);
}

int	arg_check(int argc, char **argv)
{
	int	i;
	int	arg_value;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("\033[0mError: "
			"Invalid number of arguments. Expected 5 or 6 arguments.\n");
		return (-1);
	}
	while (i < argc)
	{
		arg_value = ft_atoi(argv[i]);
		if (arg_value <= 0 || arg_value > INT32_MAX || ft_isallnum(argv[i])
			== -1 || argv[i] == 0)
		{
			printf("\033[0mError: "
				"Argument %d is not a valid positive 32-bit integer.\n", i);
			return (-3);
		}
		i++;
	}
	return (0);
}
