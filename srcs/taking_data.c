/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:07:21 by dclark            #+#    #+#             */
/*   Updated: 2021/07/20 15:16:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

void	taking_data(int ac, char **av, t_master *master)
{
	int	num_philo;
	int	i_philo;

	num_philo = ft_atoi(av[1]);
	i_philo = 0;
	master->philos = malloc(sizeof(t_philo) * num_philo);
	master->forks = malloc(sizeof(t_philo) * num_philo);
	while (i_philo < num_philo)
	{
		
		i_philo++;
	}
}
