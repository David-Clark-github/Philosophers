/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:35:53 by dclark            #+#    #+#             */
/*   Updated: 2021/07/21 11:44:52 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

void	print_philo(t_philo *philo)
{
	printf("status = %d\n", philo->status);
	printf("time_start = %d\n", philo->time_start);
	printf("time_to_eat = %d\n", philo->time_to_eat);
	printf("time_to_sleep = %d\n", philo->time_to_sleep);
	printf("satiate = %d\n", philo->satiate);
}
