/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_passed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:59:24 by dclark            #+#    #+#             */
/*   Updated: 2021/10/28 15:48:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_passed(struct timeval prog, int ID, int state)
{
	struct timeval	ongoing;
	long			res_sec;
	int				res_usec;

	gettimeofday(&ongoing, NULL);
	res_sec = ongoing.tv_sec - prog.tv_sec;
	res_usec = ongoing.tv_usec - prog.tv_usec;
	if (res_usec < 0)
		res_usec = 1000000 + res_usec;
	if (res_usec < 0)
		res_sec--;
	if (state == 1)
		printf("%.1ld.%.3dms %d has taken a fork\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 2)
		printf("%.1ld.%.3dms %d is eating\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 3)
		printf("%.1ld.%.3dms %d is sleeping\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else if (state == 4)
		printf("%.1ld.%.3dms %d is thinking\n", res_sec,
			(res_usec + 500) / 1000, ID);
	else
		printf("%.1ld.%.3dms %d died\n", res_sec, (res_usec + 500) / 1000, ID);
}
