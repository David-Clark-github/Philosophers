/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_passe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:39:56 by dclark            #+#    #+#             */
/*   Updated: 2021/11/19 17:18:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_to_passe(int adding, struct timeval *ongoing, t_philo_data *philo)
{
	long	res_sec;
	int		res_usec;

	if (adding != 0)
	{
		gettimeofday(&philo->ongoing, 0);
		res_sec = ongoing->tv_sec;
		res_usec = ongoing->tv_usec;
		res_usec += (adding * 1000);
		if (res_usec >= 1000000)
			res_sec += (res_usec / 1000000);
		if (res_usec >= 1000000)
			res_usec -= ((res_usec / 1000000) * 1000000);
		while ((ongoing->tv_sec < res_sec || ongoing->tv_usec < res_usec) \
				&& check_death(philo) == 0)
		{
			usleep(450);
			gettimeofday(&philo->ongoing, 0);
		}
	}
	else
		gettimeofday(&philo->ongoing, 0);
}
