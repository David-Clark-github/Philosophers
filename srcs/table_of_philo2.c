/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_of_philo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:16:40 by dclark            #+#    #+#             */
/*   Updated: 2021/10/31 16:32:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*table_of_philo2(void *arg)
{
	t_philo_data	*philo;
	int				i_fork;

	philo = arg;
	i_fork = philo->ID % 2;
	gettimeofday(&philo->ongoing, 0);
	while (philo->rasa != 0) {
	while (philo->initial.tv_sec > philo->ongoing.tv_sec || 
			philo->initial.tv_usec > philo->ongoing.tv_usec)
	{
		gettimeofday(&philo->ongoing, 0);
	}

	// Taking the fork if it's available
	gettimeofday(&philo->touch_death, 0);
	while (philo->num_of_fork < 2)
	{
		if (philo->fork_tab[i_fork] == -1)
		{
			pthread_mutex_lock(&philo->mutex_tab[i_fork]);
			if (philo->fork_tab[i_fork] == -1)
			{
				philo->fork_tab[i_fork] = philo->ID;
				if (philo->num_of_fork == 0)
				{
					philo->fork_status[0][0] = 1;
					philo->fork_status[0][1] = i_fork;
				}
				else
				{
					philo->fork_status[1][0] = 1;
					philo->fork_status[1][1] = i_fork;
				}
				philo->num_of_fork += 1;
				pthread_mutex_lock(philo->mutex_status);
				time_passed(philo->initial, philo->ID, 1);
				pthread_mutex_unlock(philo->mutex_status);
			}
			pthread_mutex_unlock(&philo->mutex_tab[i_fork]);
		}
		i_fork++;
		if (i_fork >= philo->num_of_philo)
			i_fork = 0;
	}
	//gettimeofday(&philo->ongoing, 0);

	//restart death_time;
	restart_death(philo);

	pthread_mutex_lock(philo->mutex_status);
	time_passed(philo->initial, philo->ID, 2);
	pthread_mutex_unlock(philo->mutex_status);

	if (check_death(philo))
	{
		*philo->death = 1;
		return (NULL);
	}
	time_to_passe(philo->time_eat, &philo->ongoing);
//	gettimeofday(&philo->ongoing, 0);

//	//	//	//	giving the fork back

//	pthread_mutex_lock(&philo->mutex_tab[philo->fork_status[0][1]]);	
	philo->fork_tab[philo->fork_status[0][1]] = -1;
//	pthread_mutex_unlock(&philo->mutex_tab[philo->fork_status[0][1]]);	
//	pthread_mutex_lock(&philo->mutex_tab[philo->fork_status[1][1]]);	
	philo->fork_tab[philo->fork_status[1][1]] = -1;
//	pthread_mutex_unlock(&philo->mutex_tab[philo->fork_status[1][1]]);	
	philo->fork_status[0][0] = -1;
	philo->fork_status[0][1] = -1;
	philo->fork_status[1][0] = -1;
	philo->fork_status[1][1] = -1;
	philo->num_of_fork = 0;

//	//	//	//

	//gettimeofday(&philo->ongoing, 0);
	pthread_mutex_lock(philo->mutex_status);
	time_passed(philo->initial, philo->ID, 3);
	pthread_mutex_unlock(philo->mutex_status);

	if (check_death(philo))
	{
		*philo->death = 1;
		return (NULL);
	}
	time_to_passe(philo->time_sleep, &philo->ongoing);

	if (check_death(philo))
	{
		*philo->death = 1;
		return (NULL);
	}
	pthread_mutex_lock(philo->mutex_status);
	time_passed(philo->initial, philo->ID, 4);
	pthread_mutex_unlock(philo->mutex_status);

	if (check_death(philo))
	{
		*philo->death = 1;
		return (NULL);
	}
	philo->rasa -= 1;
	}
	return NULL;
}
