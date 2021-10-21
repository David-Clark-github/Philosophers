/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:40:42 by dclark            #+#    #+#             */
/*   Updated: 2021/10/21 16:28:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data_dump	master;
	master.num_of_philo = ft_atoi(av[1]);
	if (check_data(ac, av) == 0)
	{
		write (1, "Error\n", ft_strlen("Error\n"));
		return (0);
	}
	master.num_of_philo = ft_atoi(av[1]);
	master.p_tab = malloc(sizeof(pthread_t) * master.num_of_philo);
	master.philo_data = malloc(sizeof(t_philo_data) * master.num_of_philo);
}
