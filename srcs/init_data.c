/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:05:58 by dclark            #+#    #+#             */
/*   Updated: 2021/10/14 17:13:51 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data_master *master, t_philo *philo_tab)
{
	int	index;

	index = 0;
	while (index < master->num_of_philo)
	{
		philo_tab[index].ID = index;
		philo_tab[index].num_of_philo = master->num_of_philo;
		philo_tab[index].tab_fork = master->tab_fork;
		philo_tab[index].num_of_fork = 0;
		philo_tab[index].fork[0][0] = -1;
		philo_tab[index].fork[1][0] = -1;
		philo_tab[index].mutex = master->mutex;
		philo_tab[index].time_val = master->time_val;
		index++;
	}	
}
