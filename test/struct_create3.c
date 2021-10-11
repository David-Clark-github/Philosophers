/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:17:07 by dclark            #+#    #+#             */
/*   Updated: 2021/10/11 14:06:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct	s_1 {
	long	time_sec;
	int		time_usec;
	int		ID;
	int		value_tab;
	int		num_of_philo2;
	pthread_mutex_t	*mutex;
	int		*tab;

}				f_1;


void	*worm(void *arg)
{
	struct timeval wait;
	gettimeofday(&wait, 0);
	f_1 *st = arg;
	int	index_tab = 0;
	while (wait.tv_usec < st->time_usec && wait.tv_sec <= st->time_sec) {
		gettimeofday(&wait, 0);
		usleep(100);
	}
	printf("1: %ld\n", st->time_sec);
	printf("2: %d\n", st->time_usec);
	while (st->value_tab == -1)
	{
		while (index_tab < st->num_of_philo2)
		{
			if (st->tab[index_tab] == -1 && st->value_tab == -1)
			{
				pthread_mutex_lock(&st->mutex[index_tab]);
				if (st->tab[index_tab] == -1)
				{
						st->tab[index_tab] = st->ID;
						st->value_tab = index_tab;
				}
				pthread_mutex_unlock(&st->mutex[index_tab]);
			}
			index_tab++;
		}
		index_tab = 0;
	}
	return NULL;
}

int main(int ac, char **av)
{
	long sec_tmp;
	int  usec_tmp;
	if (ac != 2)
	{
		printf("nombre d'argument requis: 1\n");
		return 0;
	}
	struct timeval timevals;
	f_1 *input;
	int num_of_philo = atoi(av[1]);
	pthread_mutex_t *tab_mutex;
	int index = 0;
	int	*tab;

	pthread_t *ptab;
	tab_mutex = malloc(sizeof(pthread_mutex_t) * num_of_philo);
	ptab = malloc(sizeof(pthread_t) * num_of_philo);
	input = malloc(sizeof(f_1) * num_of_philo);
	tab = malloc(sizeof(int) * num_of_philo);
	gettimeofday(&timevals, 0);
	sec_tmp = timevals.tv_sec;
	usec_tmp = timevals.tv_usec;
	for (int i = 0; i < num_of_philo; i++) {
		tab[i] = -1;
		pthread_mutex_init(&tab_mutex[i], NULL);
	}
	if (usec_tmp >= 250000) {
		sec_tmp += 1;
		usec_tmp -= 250000;
	} else {
		usec_tmp += 750000;
	}
	while (index < num_of_philo)
	{
		input[index].time_sec = sec_tmp;
		input[index].time_usec = usec_tmp;
		input[index].ID = index;
		input[index].mutex = tab_mutex;
		input[index].value_tab = -1;
		input[index].num_of_philo2 = num_of_philo;
		input[index].tab = tab;
		index++;
	}
	index = -1;
	while (++index < num_of_philo)
	{
		pthread_create(&ptab[index], NULL, *worm, &input[index]);
	}
	for (int i = 0; i < num_of_philo; i++)
		pthread_join(ptab[i], NULL);
	printf("\nsec = %ld\n", sec_tmp);
	printf("usec = %d\n", usec_tmp);
	for (int i = 0; i < num_of_philo; i++)
		printf("tab[%d] = %d\n", i, tab[i]);
}
