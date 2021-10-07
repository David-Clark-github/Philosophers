/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:20:31 by dclark            #+#    #+#             */
/*   Updated: 2021/09/22 15:47:09 by dclark           ###   ########.fr       */
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
	/*
	data_master.num_of_philo = ft_atoi(av[1]);
	data_master.time_to_die = ft_atoi(av[2]);
	data_master.time_to_eat = ft_atoi(av[3]);
	data_master.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data_master.eating_number = ft_atoi(av[5]);
	else
		data_master.eating_number = -1;
	*/
	for (int i = 3; i > 0; i--)
	{
		printf("%d\n", i);
		sleep(1);
	}
	printf("num_of_philo = %d\n", data_master.num_of_philo);
	printf("time_to_die = %d\n", data_master.time_to_die);
	printf("time_to_eat = %d\n", data_master.time_to_eat);
	printf("time_to_sleep = %d\n", data_master.time_to_sleep);
	printf("eating_number = %d\n", data_master.eating_number);
	return 0;
}
