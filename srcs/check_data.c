/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:52:26 by dclark            #+#    #+#             */
/*   Updated: 2021/09/22 14:55:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(int ac, char **av)
{
	int	i_av;
	int	i_str;

	i_av = 1;
	while (i_av < ac)
	{
		i_str = -1;
		if (ft_strlen(av[i_av]) == 0)
			return (0);
		while (av[i_av][++i_str])
			if (!ft_isdigit(av[i_av][i_str]))
				return (0);
		i_av++;
	}
	return (1);
}
