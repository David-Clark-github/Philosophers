/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:41:59 by dclark            #+#    #+#             */
/*   Updated: 2021/10/21 17:08:19 by dclark           ###   ########.fr       */
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
//	write(1, "time_stamp: ", ft_strlen("time_stamp: "));
//	ft_putnbr(seconds);
//	ft_putnbr((long)micro);
//	write(1, "\n", 1);
	printf("time_stamp %ld.%d\n", seconds, micro);
}
