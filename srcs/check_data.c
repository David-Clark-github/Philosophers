/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:52:26 by dclark            #+#    #+#             */
/*   Updated: 2021/11/02 17:05:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

/*

long		ft_atoi(char *str)
{
	long	res;
	int		index;

	index = 0;
	res = 0;
	while (str[index])
	{
		res = (res * 10) + (str[i] - '0');
		index++;
	}
	return (res);
}
*/

static int	check_limits(char *av)
{
	if (ft_atoi(av) > INT_MAX || ft_atoi(av) < INT_MIN)
		return 1;
	return 0;	
}

int	check_data(int ac, char **av)
{
	int	i_av;
	int	i_str;

	i_av = 1;
	if (ac > 6 || ac < 5)
		return (0);
	while (i_av < ac)
	{
		i_str = -1;
		if ((ft_strlen(av[i_av]) == 0 || ft_strlen(av[i_av]) > 10 \
					|| check_limits(av[i_av]))
			return (0);
		while (av[i_av][++i_str])
			if (!ft_isdigit(av[i_av][i_str]))
				return (0);
		i_av++;
	}
	return (1);
}
