/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:05:14 by dclark            #+#    #+#             */
/*   Updated: 2021/10/15 15:12:27 by dclark           ###   ########.fr       */
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
	while ((tmp.tv_sec < philo->progress.tv_sec) || 
			(tmp.tv_usec <= philo->progress.tv_usec))
	{
		gettimeofday(&tmp, 0);
		usleep(100);
	}
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
				{
					philo->fork[0][0] = 1;
					philo->fork[0][1] = i_fork;
				}
				else
				{
					philo->fork[1][0] = 1;
					philo->fork[1][1] = i_fork;
				}
				philo->num_of_fork += 1;
			}
			pthread_mutex_unlock(&philo->mutex[i_fork]);
		}
		i_fork++;
	}
//	printf("ID %d is eating\n", philo->ID);
	philo_status(philo, 1);	
	usleep(200000);
	pthread_mutex_lock(&philo->mutex[philo->fork[0][1]]);
	philo->tab_fork[philo->fork[0][1]] = -1;
	pthread_mutex_unlock(&philo->mutex[philo->fork[0][1]]);
	pthread_mutex_lock(&philo->mutex[philo->fork[1][1]]);
	philo->tab_fork[philo->fork[1][1]] = -1;
	pthread_mutex_unlock(&philo->mutex[philo->fork[1][1]]);
	philo->fork[1][0] = -1;
	philo->fork[0][0] = -1;
	printf("ID %d is sleep\n", philo->ID);
	usleep(500000);
	return NULL;
}
