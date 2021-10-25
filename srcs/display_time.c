/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:41:59 by dclark            #+#    #+#             */
/*   Updated: 2021/10/25 10:48:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_time(struct timeval initial, struct timeval progress)
{
	long	seconds;
	int		micro;

	seconds = progress.tv_sec - initial.tv_sec;
	micro = (progress.tv_usec + 500 - initial.tv_usec) / 1000;
	if (micro > 1000000)
	{
		seconds++;
		micro -= 1000000;
	}
	printf("time_stamp %ld.%d\n", seconds, micro);
}
