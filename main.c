/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:40:42 by dclark            #+#    #+#             */
/*   Updated: 2021/10/21 14:50:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	*philo;
	int			num_of_philo;

	if (check_data(ac, av) == 0)
	{
		write (1, "Error\n", ft_strlen("Error\n"));
		return (0);
	}
	num_of_philo = ft_atoi(av[1]);
	philo = malloc(sizeof(pthread_t) * num_of_philo);

}
