/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:56:15 by dclark            #+#    #+#             */
/*   Updated: 2021/10/21 17:13:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_status(t_philo *philo, int status)
{
	display_time(philo->initial, philo->progress);
	ft_putnbr(philo->ID);
	if (status == 0)
		write(1, " has taken a fork\n", ft_strlen(" has taken a fork\n"));
	if (status == 1)
		write(1, " is eating\n", ft_strlen("is eating\n"));
	if (status == 2)
		write(1, " is sleeping\n", ft_strlen(" is sleeping\n"));
	if (status == 3)
		write(1, " died", ft_strlen(" died"));
}
