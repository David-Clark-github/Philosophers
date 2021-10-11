/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:05:14 by dclark            #+#    #+#             */
/*   Updated: 2021/10/11 16:37:45 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*table_of_philo(void *arg)
{
	int i_fork;
	t_philo *philo;
	philo = arg;
	printf("ID = %d\n", philo->ID);
	i_fork = 0;
	while (i_fork < philo->num_of_philo && philo->num_of_fork < 2)
	{
		if (philo->tab_fork[i_fork] == -1)
		{
			pthread_mutex_lock(&philo->mutex[i_fork]);
			if (philo->tab_fork[i_fork] == -1)
			{
				philo->tab_fork[i_fork] = philo->ID;
				if (philo->num_of_fork == 0)
					philo->fork[0] = 1;
				else
					philo->fork[1] = 1;
				philo->num_of_fork += 1;
			}
			pthread_mutex_unlock(&philo->mutex[i_fork]);
		}
		i_fork++;
	}
	return NULL;
}
