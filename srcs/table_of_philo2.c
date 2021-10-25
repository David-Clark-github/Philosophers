/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:16:40 by dclark            #+#    #+#             */
/*   Updated: 2021/10/25 14:24:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*table_of_philo2(void *arg)
{
	t_philo_data	*philo;
	int				i_fork;

	philo = arg;
	i_fork = philo->ID;
	gettimeofday(&philo->ongoing, 0);
	while (philo->initial.tv_sec < philo->ongoing.tv_sec || 
		philo->initial.tv_usec < philo->ongoing.tv_usec)
	{
		gettimeofday(&philo->ongoing, 0);
	}
	while (philo->num_of_fork < 2)
	{
		
		i_fork++;
		if (i_fork = philo->num_of_fork)
			i_fork = 0;
	}
	return NULL;
}
