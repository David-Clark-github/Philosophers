/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:17:07 by dclark            #+#    #+#             */
/*   Updated: 2021/09/19 15:20:25 by david            ###   ########.fr       */
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
	int		*value;
}				f_1;

pthread_mutex_t mutex;

void	*worm(void *arg)
{
	struct timeval timevals;
	f_1 *st = arg;
	int flag = 1;
	printf("ID: %.2d\n", st->ID);
	while (flag)
	{
		usleep(400);
		gettimeofday(&timevals, 0);
		if (st->toto.tv_sec == timevals.tv_sec)
		{
			pthread_mutex_lock(&mutex);
			*st->value = *st->value + 1;
			printf("ID: %.2d time = %.2ld value = %.2d\n", st->ID, timevals.tv_sec, *st->value);
			usleep(50);
			pthread_mutex_unlock(&mutex);
			flag = 0;
		}
	}
	return NULL;
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("manque un argument\n");
		return 0;
	}
	struct timeval mani;
	f_1 *input;
	int	val_input = atoi(av[2]);
	int num_of_philo = atoi(av[1]);
	int index = 0;
	long timet;

	pthread_t *ptab;
	gettimeofday(&mani, 0);
	pthread_mutex_init(&mutex, NULL);
	timet = mani.tv_sec + 2;
	ptab = malloc(sizeof(pthread_t) * num_of_philo);
	input = malloc(sizeof(f_1) * num_of_philo);
	printf("Value_input = %d\n", val_input);

	while (index < num_of_philo)
	{
		input[index].ID = index;
		input[index].toto.tv_sec = timet;
		input[index].value = &val_input;
		pthread_create(&ptab[index], NULL, *worm, &input[index]);
		index++;
//		usleep(75);
	}
	for (int i = 0; i < num_of_philo; i++)
		pthread_join(ptab[i], NULL);
}
