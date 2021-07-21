/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:06:07 by dclark            #+#    #+#             */
/*   Updated: 2021/07/21 11:44:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

int main(int ac, char **av)
{
	t_master master;
	if (ac < 5 || ac > 6)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (0);
	}
	if (!check_data(ac, av))
	{
		write(1, "Wrong argument(s)\n", 18);
		return (0);
	}
	else
	{
		write(1, "OK\n", 3);
		taking_data(ac, av, &master);
		//continue
	}
	print_philo(&master.philos[0]);
}
