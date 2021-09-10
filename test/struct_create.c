/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:17:07 by dclark            #+#    #+#             */
/*   Updated: 2021/09/10 14:33:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct	s_1 {
//	long	time_value;
	struct timeval toto;
	int		ID;
}				f_1;

void	*worm(void *arg)
{
	struct timeval timevals;
	f_1 *st = arg;
	int flag = 1;
	printf("ID = %d\n", st->ID);
	while (flag)
	{
		usleep(400);
		gettimeofday(&timevals, 0);
		if (st->toto.tv_sec == timevals.tv_sec)
		{
			printf("ID: %d time = %ld\n", st->ID, timevals.tv_sec);
			flag = 0;
		}
	}
	return NULL;
}

int main(int ac, char **av)
{
	struct timeval mani;
	f_1 *input;
	int num_of_philo = atoi(av[1]);
	int index = 0;
	long timet;

	pthread_t *ptab;
	gettimeofday(&mani, 0);
	timet = mani.tv_sec + 2;
	ptab = malloc(sizeof(pthread_t) * num_of_philo);
	input = malloc(sizeof(f_1) * num_of_philo);

	while (index < num_of_philo)
	{
		input[index].ID = index;
		input[index].toto.tv_sec = timet;
		pthread_create(&ptab[index], NULL, *worm, &input[index]);
		index++;
		usleep(100);
	}
	for (int i = 0; i < num_of_philo; i++)
		pthread_join(ptab[i], NULL);
}
