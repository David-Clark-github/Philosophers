/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:55:15 by dclark            #+#    #+#             */
/*   Updated: 2021/11/21 22:57:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taking_fork_1(t_philo_data *philo, int fork_1, int fork_2)
{
	pthread_mutex_lock(&philo->mutex_tab[fork_1]);
	if (philo->fork_tab[fork_1] == -1)
	{
		philo->fork_status[0][1] = fork_1;
		philo->fork_tab[fork_1] = fork_1;
		philo->num_of_fork += 1;
		time_passed(philo->initial, 1, philo);
	}
	pthread_mutex_unlock(&philo->mutex_tab[fork_1]);
	pthread_mutex_lock(&philo->mutex_tab[fork_2]);
	if (philo->fork_tab[fork_2] == -1)
	{
		philo->fork_status[1][1] = fork_2;
		philo->fork_tab[fork_2] = fork_2;
		philo->num_of_fork += 1;
		time_passed(philo->initial, 1, philo);
	}
	pthread_mutex_unlock(&philo->mutex_tab[fork_2]);
}

void	taking_fork(t_philo_data *philo)
{
	int	fork_1;
	int	fork_2;

	fork_1 = philo->id - 1;
	fork_2 = philo->id - 2;
	if (philo->id == 1)
		fork_2 = philo->num_of_philo - 1;
	while (philo->num_of_fork < 2 && check_death(philo) == 0)
		taking_fork_1(philo, fork_1, fork_2);
}
