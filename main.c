/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:40:42 by dclark            #+#    #+#             */
/*   Updated: 2021/10/25 17:28:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data_dump	master;
	int			master_death;
	struct		timeval prog;
	master_death = 0;
	master.num_of_philo = ft_atoi(av[1]);
	if (check_data(ac, av) == 0)
	{
		write (1, "Error\n", ft_strlen("Error\n"));
		return (0);
	}
	master.num_of_philo = ft_atoi(av[1]);
	master.p_tab = malloc(sizeof(pthread_t) * master.num_of_philo);
	master.philo_data = malloc(sizeof(t_philo_data) * master.num_of_philo);
	master.fork_tab = malloc(sizeof(int) * master.num_of_philo);
	master.mutex_tab = malloc(sizeof(pthread_mutex_t) * master.num_of_philo);
	for (int i = 0; i < master.num_of_philo; i++)
	{
		master.fork_tab[i] = -1;
		pthread_mutex_init(&master.mutex_tab[i], NULL);
	}	
	gettimeofday(&prog, 0);
	prog.tv_sec += 1;
	for (int i = 0; i < master.num_of_philo; i++)
	{
		master.philo_data[i].ID = i;
		master.philo_data[i].initial = prog;
		master.philo_data[i].mutex_tab = master.mutex_tab;
		master.philo_data[i].death = &master_death;
		master.philo_data[i].fork_tab = master.fork_tab;
		master.philo_data[i].num_of_philo = master.num_of_philo;
		master.philo_data[i].num_of_fork = 0;
		master.philo_data[i].time_die = ft_atoi(av[2]);
		master.philo_data[i].time_eat = ft_atoi(av[3]);
		master.philo_data[i].time_sleep = ft_atoi(av[4]);
		if (ac > 5)
			master.philo_data[i].time_rasa = ft_atoi(av[4]);
		else
			master.philo_data[i].time_rasa = -1;
		master.philo_data[i].mutex_tab = master.mutex_tab;
	}
	for (int i = 0; i < master.num_of_philo; i++)
		pthread_create(&master.p_tab[i], NULL, &table_of_philo2, &master.philo_data[i]);
	for (int i = 0; i < master.num_of_philo; i++)
		pthread_join(master.p_tab[i], 0);
}
