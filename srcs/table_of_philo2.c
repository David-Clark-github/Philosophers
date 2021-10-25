/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:16:40 by dclark            #+#    #+#             */
/*   Updated: 2021/10/25 17:28:17 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*table_of_philo2(void *arg)
{
	t_philo_data	*philo;
	int				i_fork;
	int				num_tab;

	philo = arg;
	i_fork = 0;
	gettimeofday(&philo->ongoing, 0);
	num_tab = philo->num_of_philo;
	while (philo->initial.tv_sec < philo->ongoing.tv_sec || 
		philo->initial.tv_usec < philo->ongoing.tv_usec)
	{
		gettimeofday(&philo->ongoing, 0);
	}
	gettimeofday(&philo->initial, 0);
	while (philo->num_of_fork < 2 && num_tab)
	{
		if (philo->fork_tab[i_fork] == -1)
		{
			pthread_mutex_lock(&philo->mutex_tab[i_fork]);
			if (philo->fork_tab[i_fork] == -1)
			{
				printf("ID: %d\n", philo->ID);
				philo->fork_tab[i_fork] = philo->ID;
				if (philo->num_of_fork == 0)
				{
					philo->fork_status[0][0] = 1;
					philo->fork_status[0][1] = i_fork;
				}
				else
				{
					philo->fork_status[1][0] = 1;
					philo->fork_status[1][1] = i_fork;
				}
				philo->num_of_fork += 1;
				num_tab--;
				time_passed(philo->initial, philo->ID, 1);
			}
			pthread_mutex_unlock(&philo->mutex_tab[i_fork]);
		}
		i_fork++;
		if (i_fork >= philo->num_of_fork)
			i_fork = 0;
	}
	return NULL;
}
