/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:42:32 by dclark            #+#    #+#             */
/*   Updated: 2021/11/17 15:52:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*kill_philo(t_philo_data *philo)
{
	bool	death;

	pthread_mutex_lock(philo->mutex_death);
	death = *philo->death == philo->id;
	pthread_mutex_unlock(philo->mutex_death);
	if (death)
		time_passed(philo->initial, 5, philo);
	return (NULL);
}
