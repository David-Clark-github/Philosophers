/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:05:14 by dclark            #+#    #+#             */
/*   Updated: 2021/10/14 12:17:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*table_of_philo(void *arg)
{
	int i_fork;
	struct timeval	tmp;
	t_philo *philo;
	philo = arg;
	gettimeofday(&tmp, 0);
	while (tmp.tv_sec != philo->time_val.tv_sec)
	{
		gettimeofday(&tmp, 0);
		usleep(100);
	}
	printf("ID = %d\n", philo->ID);
	i_fork = philo->ID;
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
