/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:17 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/31 15:50:32 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int arg_check(int argc, char**argv)
{    
    int i = 1;
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
