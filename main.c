/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:40:42 by dclark            #+#    #+#             */
/*   Updated: 2021/11/17 16:04:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_master(t_data_dump *master)
{
	int	i;

	i = 0;
	while (i < master->num_of_philo)
	{
		pthread_mutex_destroy(&master->mutex_tab[i]);
		i++;
	}
	pthread_mutex_destroy(&master->mutex_status);
	free(master->p_tab);
	free(master->philo_data);
	free(master->fork_tab);
	free(master->mutex_tab);
}

int	return_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data_dump		master;
	struct timeval	prog;
	int				i;

	if (check_data(ac, av) == 0)
		return (return_error("Error\n"));
	if (taking_data(av, &master) == 1)
		return_error("Error malloc\n");
	gettimeofday(&prog, 0);
	prog.tv_sec += 1;
	init_data(ac, av, &master, &prog);
	i = 0;
	while (i < master.num_of_philo)
	{
		pthread_create(&master.p_tab[i], NULL, &table_of_philo2, \
			&master.philo_data[i]);
		i++;
	}
	i = 0;
	while (i < master.num_of_philo)
	{
		pthread_join(master.p_tab[i], NULL);
		i++;
	}
	free_master(&master);
}
