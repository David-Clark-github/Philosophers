/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:20:31 by dclark            #+#    #+#             */
/*   Updated: 2021/10/11 13:45:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_data_master	data_master;
	if (check_data(ac, av) == 0 || (ac < 5 || ac > 6))
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	taking_data(ac, av, &data_master);
//	/*
	for (int i = 0; i < data_master.num_of_philo; i++)
		printf("ID = %d value = %d\n", i, data_master.tab_fork[i]);
//	*/
//	/*
	printf("num_of_philo = %d\n", data_master.num_of_philo);
	printf("time_to_die = %d\n", data_master.time_to_die);
	printf("time_to_eat = %d\n", data_master.time_to_eat);
	printf("time_to_sleep = %d\n", data_master.time_to_sleep);
	printf("eating_number = %d\n", data_master.eating_number);
//	*/
	return 0;
}
