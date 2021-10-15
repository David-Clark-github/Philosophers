/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:20:31 by dclark            #+#    #+#             */
/*   Updated: 2021/10/15 13:19:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_data_master	data_master;
	t_philo			*philo_tab;
	int				index;

	if (check_data(ac, av) == 0 || (ac < 5 || ac > 6))
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	index = 0;
	taking_data(ac, av, &data_master);
	philo_tab = malloc(sizeof(t_philo) * data_master.num_of_philo);
	init_data(&data_master, philo_tab);
	/*
	while (index < data_master.num_of_philo)
	{
		philo_tab[index].ID = index;
		philo_tab[index].tab_fork = data_master.tab_fork;
		philo_tab[index].fork[0] = -1;
		philo_tab[index].fork[1] = -1;
		philo_tab[index].mutex = data_master.mutex;
		index++;
	}
	*/
	index = 0;
	while (index < data_master.num_of_philo)
	{
		pthread_create(&data_master.ptab[index], NULL, *table_of_philo, &philo_tab[index]);
		index++;
	}
	index = 0;
	while (index < data_master.num_of_philo)
	{
		pthread_join(data_master.ptab[index], NULL);
		index++;
	}
	// TEST
	
	for (int i = 0; i < data_master.num_of_philo; i++)
		printf("[%d] = %d\n", i, data_master.tab_fork[i]);

	// END TEST

	return 0;
}
