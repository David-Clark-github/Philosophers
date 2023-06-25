/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:05:58 by dclark            #+#    #+#             */
/*   Updated: 2021/11/15 15:58:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_2(t_data_dump *master, int i, char **av)
{
	master->philo_data[i].fork_status[0][0] = -1;
	master->philo_data[i].fork_status[0][1] = -1;
	master->philo_data[i].fork_status[1][0] = -1;
	master->philo_data[i].fork_status[1][1] = -1;
	master->philo_data[i].time_die = ft_atoi(av[2]);
	master->philo_data[i].time_eat = ft_atoi(av[3]);
	master->philo_data[i].time_sleep = ft_atoi(av[4]);
}

void	init_data(int ac, char **av, t_data_dump *master, struct timeval *prog)
{
	int	i;

	pthread_mutex_init(&master->mutex_status, NULL);
	pthread_mutex_init(&master->mutex_death, NULL);
	i = 0;
	master->master_death = 0;
	while (i < master->num_of_philo)
	{
		master->philo_data[i].id = i + 1;
		master->philo_data[i].initial = *prog;
		master->philo_data[i].death = &master->master_death;
		master->philo_data[i].mutex_death = &master->mutex_death;
		master->philo_data[i].fork_tab = master->fork_tab;
		master->philo_data[i].mutex_tab = master->mutex_tab;
		master->philo_data[i].mutex_status = &master->mutex_status;
		master->philo_data[i].num_of_philo = master->num_of_philo;
		master->philo_data[i].num_of_fork = 0;
		init_2(master, i, av);
		if (ac > 5)
			master->philo_data[i].rasa = ft_atoi(av[5]);
		else
			master->philo_data[i].rasa = -1;
		i++;
	}
}
