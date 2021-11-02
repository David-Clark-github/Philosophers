/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_passed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:59:24 by dclark            #+#    #+#             */
/*   Updated: 2021/11/02 18:26:02 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print(long res_sec, int res_usec, int ID, int state)
{
	if (state == 1)
		printf("%ld%.3d %d has taken a fork\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 2)
		printf("%ld%.3d %d is eating\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 3)
		printf("%ld%.3d %d is sleeping\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 4)
		printf("%ld%.3d %d is thinking\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else
		printf("%ld%.3d %d died\n", res_sec, (res_usec + 500) / 1000, ID);
}

void	time_passed(struct timeval prog, int ID, int state, t_philo_data *philo)
{
	struct timeval	ongoing;
	long			res_sec;
	int				res_usec;

	pthread_mutex_lock(philo->mutex_status);
	if (philo->death != 0)
	{
		gettimeofday(&ongoing, NULL);
		res_sec = ongoing.tv_sec - prog.tv_sec;
		res_usec = ongoing.tv_usec - prog.tv_usec;
		if (res_usec < 0)
		{
			res_sec--;
			res_usec += 1000000;
		}
		print(res_sec, res_usec, ID, state);
	}
	pthread_mutex_unlock(philo->mutex_status);
}
