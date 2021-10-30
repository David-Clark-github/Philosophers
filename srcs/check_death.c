/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:38:56 by dclark            #+#    #+#             */
/*   Updated: 2021/10/30 19:07:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo_data *philo)
{
	long	total_res;
	int		tmp_sec;
	long	tmp_usec;

	tmp_sec = philo->touch_death.tv_sec;
	tmp_usec = philo->touch_death.tv_usec;
	gettimeofday(&philo->touch_death, 0);
	total_res = (philo->touch_death.tv_sec - tmp_sec) * 1000000;
	total_res += philo->touch_death.tv_usec - tmp_usec;
	printf("%d total_death = %ld\n", philo->ID, (total_res + 500) / 1000);
	if ((total_res + 500) / 1000 >= philo->time_die)
		return (1);
	return (0);
}
