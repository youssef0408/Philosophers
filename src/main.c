/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:09:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:31 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char**argv)
{
    t_info info;
    
   if(arg_check(argc, argv))
        return(1);
    init_dinner(&info, argv);
    if(thread_launch(&info))
    {
        printf("\033[0mError: Threads creation failed\n");
        return(1);
    }
    return(0);
}
