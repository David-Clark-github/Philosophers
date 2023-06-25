/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:07:21 by dclark            #+#    #+#             */
/*   Updated: 2021/11/15 15:58:44 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	taking_data(char **av, t_data_dump *master)
{
	int	i;

	i = 0;
	master->num_of_philo = ft_atoi(av[1]);
	master->p_tab = malloc(sizeof(pthread_t) * master->num_of_philo);
	if (master->p_tab == NULL)
		return (1);
	master->philo_data = malloc(sizeof(t_philo_data) * master->num_of_philo);
	if (master->philo_data == NULL)
		return (1);
	master->fork_tab = malloc(sizeof(int) * master->num_of_philo);
	if (master->fork_tab == NULL)
		return (1);
	master->mutex_tab = malloc(sizeof(pthread_mutex_t) * master->num_of_philo);
	if (master->mutex_tab == NULL)
		return (1);
	while (i < master->num_of_philo)
	{
		master->fork_tab[i] = -1;
		pthread_mutex_init(&master->mutex_tab[i], NULL);
		i++;
	}
	return (0);
}
