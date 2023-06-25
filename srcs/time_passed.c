/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_passed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:59:24 by dclark            #+#    #+#             */
/*   Updated: 2021/11/22 12:59:31 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print(long res_sec, int res_usec, int state, t_philo_data *philo)
{
	if (state == 1)
		printf("%ld%.3d %d has taken a fork\n", res_sec,
			(res_usec + 500) / 1000, philo->id);
	else if (state == 2)
	{
		printf("%ld%.3d %d is eating\n", res_sec,
			(res_usec + 500) / 1000, philo->id);
		restart_death(philo);
	}
	else if (state == 3)
		printf("%ld%.3d %d is sleeping\n", res_sec,
			(res_usec + 500) / 1000, philo->id);
	else if (state == 4)
		printf("%ld%.3d %d is thinking\n", res_sec,
			(res_usec + 500) / 1000, philo->id);
	else if (state == 5)
	{
		pthread_mutex_lock(philo->mutex_death);
		if (*philo->death == philo->id)
			printf("%ld%.3d %d died\n", res_sec, \
			(res_usec + 500) / 1000, philo->id);
		pthread_mutex_unlock(philo->mutex_death);
	}
}

void	time_passed(struct timeval prog, int state, t_philo_data *philo)
{
	struct timeval	ongoing;
	long			res_sec;
	int				res_usec;

	gettimeofday(&ongoing, NULL);
	res_sec = ongoing.tv_sec - prog.tv_sec;
	res_usec = ongoing.tv_usec - prog.tv_usec;
	if (res_usec < 0)
	{
		res_sec--;
		res_usec += 1000000;
	}
	pthread_mutex_lock(philo->mutex_status);
	print(res_sec, res_usec, state, philo);
	pthread_mutex_unlock(philo->mutex_status);
}
