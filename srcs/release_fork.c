/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:09:01 by dclark            #+#    #+#             */
/*   Updated: 2021/11/15 14:11:08 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_fork(t_philo_data *philo)
{
	pthread_mutex_lock(&philo->mutex_tab[philo->fork_status[0][1]]);
	philo->fork_tab[philo->fork_status[0][1]] = -1;
	pthread_mutex_unlock(&philo->mutex_tab[philo->fork_status[0][1]]);
	pthread_mutex_lock(&philo->mutex_tab[philo->fork_status[1][1]]);
	philo->fork_tab[philo->fork_status[1][1]] = -1;
	pthread_mutex_unlock(&philo->mutex_tab[philo->fork_status[1][1]]);
	philo->fork_status[0][0] = -1;
	philo->fork_status[0][1] = -1;
	philo->fork_status[1][0] = -1;
	philo->fork_status[1][1] = -1;
	philo->num_of_fork = 0;
}
