/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:17:07 by dclark            #+#    #+#             */
/*   Updated: 2021/09/21 15:54:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct	s_1 {
	int		ID;
	int		value_tab;
	int		num_of_philo2;
	int		*tab;
}				f_1;

pthread_mutex_t mutex;

void	*worm(void *arg)
{
	f_1 *st = arg;
	int	index_tab = 0;
	printf("ID: %.2d\n", st->ID);
	while (st->value_tab == -1)
	{
			while (index_tab < num_of_philo2)
			{
					if (st->tab[index_tab] == -1 && st->value_tab == -1)
					{
							pthread_mutex_lock(&mutex);
							if (st->tab[index_tab] == -1)
							{
									st->tab[index_tab] = st->ID;
									st->value_tab = index;
							}
							pthread_mutex_unlock(&mutex);
					}
					index_tab++;
			}
			index_tab = 0;
	}
	return NULL;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("nombre d'argument requis: 2\n");
		return 0;
	}
	f_1 *input;
	int num_of_philo = atoi(av[1]);
	int index = 0;
	int	*tab

	pthread_t *ptab;
	pthread_mutex_init(&mutex, NULL);
	ptab = malloc(sizeof(pthread_t) * num_of_philo);
	input = malloc(sizeof(f_1) * num_of_philo);
	tab = malloc(sizeof(int) * num_of_philo);

	while (index < num_of_philo)
	{
		input[index].ID = index;
		input[index].value_tab = -1;
		input[index].num_of_philo2 = num_of_philo;
		input[index].tab = tab;
		pthread_create(&ptab[index], NULL, *worm, &input[index]);
		index++;
//		usleep(75);
	}
	for (int i = 0; i < num_of_philo; i++)
		pthread_join(ptab[i], NULL);
}
