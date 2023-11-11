/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:09:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/11/10 15:14:22 by yothmani         ###   ########.fr       */
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
}
