/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:07:21 by dclark            #+#    #+#             */
/*   Updated: 2021/07/21 13:02:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

void	taking_data(int ac, char **av, t_master *master)
{
	int	i_philo;

	i_philo = 0;
	master->num_philo = ft_atoi(av[ARG_PHILO]);
	master->philos = malloc(sizeof(t_philo) * master->num_philo);
	master->forks = malloc(sizeof(t_philo) * master->num_philo);
	while (i_philo < master->num_philo)
	{
		master->philos[i_philo].status = PH_THINK;
		master->philos[i_philo].time_to_eat = ft_atoi(av[ARG_EAT]);
		master->philos[i_philo].time_to_sleep = ft_atoi(av[ARG_SLEEP]);
		master->philos[i_philo].time_bfor_death = ft_atoi(av[ARG_DEAD]);
		if (ac == 6)
			master->philos[i_philo].satiate = ft_atoi(av[ARG_SATIA]);
		i_philo++;
	}
}
