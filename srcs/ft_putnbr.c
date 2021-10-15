/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:12:16 by dclark            #+#    #+#             */
/*   Updated: 2021/10/15 15:03:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


static void	print(char c)
{
	write(1, &c, 1);
}
/*
void	print_long(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		print(c[i]);
		i++;
	}
}

void	algo(int nb)
{
	int div;

	div = 1000000000;
	while (div > nb)
		div /= 10;
	while (div >= 1)
	{
		print((nb / div) + '0');
		nb = nb - ((nb / div) * div);
		div /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 2147483647)
		print_long("2147483647");
	else if (nb == -2147483648)
		print_long("-2147483648");
	else if (nb < 0)
	{
		print('-');
		nb = nb * -1;
		algo(nb);
	}
	else if (nb == 0)
		print(0 + '0');
	else
		algo(nb);
}
*/


void	ft_putnbr(long nb)
{
	if (nb < 10)
		print(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
