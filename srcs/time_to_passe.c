/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_passe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:39:56 by dclark            #+#    #+#             */
/*   Updated: 2021/10/26 16:44:59 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_to_passe(int adding, struct timeval *ongoing)
{
	long	res_sec;
	int		res_usec;

	res_sec = ongoing->tv_sec;
	res_usec = ongoing->tv_usec;
	res_usec = res_usec + (adding * 1000);
	if (res_usec >= 1000000)
	{
		res_sec += (res_usec / 1000000);
		res_usec -= ((res_usec / 1000000) * 1000000);
	}
	while (ongoing->tv_sec < res_sec || ongoing->tv_usec < res_usec)
		gettimeofday(ongoing, NULL);
}
