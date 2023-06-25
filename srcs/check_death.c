/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:38:56 by dclark            #+#    #+#             */
/*   Updated: 2021/11/19 17:42:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo_data *philo)
{
	long	total_res;

	pthread_mutex_lock(philo->mutex_death);
	if (*philo->death != 0)
	{
		pthread_mutex_unlock(philo->mutex_death);
		return (1);
	}
	else
		pthread_mutex_unlock(philo->mutex_death);
	gettimeofday(&philo->ongoing, NULL);
	total_res = (philo->ongoing.tv_sec - philo->touch_death.tv_sec) * 1000000;
	total_res += (philo->ongoing.tv_usec - philo->touch_death.tv_usec);
	if (total_res / 1000 >= philo->time_die)
	{
		pthread_mutex_lock(philo->mutex_death);
		if (*philo->death == 0)
			*philo->death = philo->id;
		pthread_mutex_unlock(philo->mutex_death);
		return (1);
	}
	return (0);
}
