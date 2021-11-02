/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:42:32 by dclark            #+#    #+#             */
/*   Updated: 2021/11/02 16:11:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*kill_philo(t_philo_data *philo)
{
	philo->fork_tab[philo->fork_status[0][1]] = -1;
	philo->fork_tab[philo->fork_status[1][1]] = -1;
//	*philo->death = philo->ID;	
	if (*philo->death == philo->ID)
		time_passed(philo->initial, philo->ID, 5, philo);
	return (NULL);
}
