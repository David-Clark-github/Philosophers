/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:38:56 by dclark            #+#    #+#             */
/*   Updated: 2021/11/01 17:27:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo_data *philo)
{
	long	total_res;

	if (*philo->death != 0)
		return (1);
//	gettimeofday(&philo->touch_death, 0);
	total_res = (philo->ongoing.tv_sec - philo->touch_death.tv_sec) * 1000000;
	total_res += (philo->ongoing.tv_usec -  philo->touch_death.tv_usec);
	//printf("ID: %d total_res = %ld\n", philo->ID, (total_res + 500) / 1000);
	if ((total_res /*+ 500*/) / 1000 >= philo->time_die)
	{
		*philo->death = philo->ID;
		return (1);
	}
	return (0);
}
