/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:16:40 by dclark            #+#    #+#             */
/*   Updated: 2021/11/22 12:59:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo(t_philo_data *philo)
{
	if (philo->rasa == 0)
		return (NULL);
	time_passed(philo->initial, 1, philo);
	time_to_passe(philo->time_die, &philo->ongoing, philo);
	pthread_mutex_lock(philo->mutex_death);
	*philo->death = philo->id;
	pthread_mutex_unlock(philo->mutex_death);
	time_passed(philo->initial, 5, philo);
	return (NULL);
}

static void	reduce_code(t_philo_data *philo, int i)
{
	time_passed(philo->initial, i, philo);
	if (i == 2)
		time_to_passe(philo->time_eat, &philo->ongoing, philo);
	else if (i == 3)
		time_to_passe(philo->time_sleep, &philo->ongoing, philo);
}

static void	*reduce_code2(t_philo_data *philo)
{
	if (check_death(philo))
		return (kill_philo(philo));
	taking_fork(philo);
	if (check_death(philo))
		return (kill_philo(philo));
	reduce_code(philo, 2);
	if (check_death(philo))
		return (kill_philo(philo));
	release_fork(philo);
	reduce_code(philo, 3);
	if (check_death(philo))
		return (kill_philo(philo));
	time_passed(philo->initial, 4, philo);
	if (check_death(philo))
		return (kill_philo(philo));
	return ("");
}

void	*table_of_philo2(void *arg)
{
	t_philo_data	*philo;

	philo = arg;
	grid_philo(philo);
	if (philo->num_of_philo == 1)
		return (one_philo(philo));
	while (philo->rasa != 0)
	{
		if (reduce_code2(philo) == NULL)
			return (NULL);
		philo->rasa -= 1;
	}
	return (NULL);
}
