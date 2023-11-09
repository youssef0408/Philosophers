/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:09:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/08 19:22:38 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char**argv)
{
    struct timeval	t;
    t_info info;
    
   if(arg_check(argc, argv))
        return(1);
    init_dinner(&info, argv);
    gettimeofday(&t, NULL);
}

