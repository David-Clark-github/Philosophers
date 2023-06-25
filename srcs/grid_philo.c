/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:22:47 by dclark            #+#    #+#             */
/*   Updated: 2021/11/21 22:21:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grid_philo(t_philo_data *philo)
{
	gettimeofday(&philo->ongoing, 0);
	while (philo->initial.tv_sec > philo->ongoing.tv_sec || \
			philo->initial.tv_usec > philo->ongoing.tv_usec)
	{
		gettimeofday(&philo->touch_death, 0);
		gettimeofday(&philo->ongoing, 0);
	}
	restart_death(philo);
	check_death(philo);
	if (philo->id % 2 == 0)
		time_to_passe(philo->time_eat, &philo->ongoing, philo);
}
