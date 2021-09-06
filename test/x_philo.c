/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:14:03 by dclark            #+#    #+#             */
/*   Updated: 2021/09/06 16:50:53 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


void	*ft_1(void *arg)
{
	struct timeval timevals;
	int *value = arg;
	int flag = 0;
	while (flag == 0)
	{
		usleep(500);
		gettimeofday(&timevals, 0);
		if (*value == timevals.tv_sec)
		{
			printf("time = %ld\n", timevals.tv_sec);
			flag = 1;
		}
	}
	return NULL;
}

int main(int ac, char **av) {

	struct timeval timevals;
	int num_of_philo = atoi(av[1]);
	int	index = 0;
	int	timet;

	pthread_t *tab;
	gettimeofday(&timevals, 0);
	timet = timevals.tv_sec + 2;
	tab = malloc(sizeof(pthread_t) * num_of_philo);

	while (index < num_of_philo)
	{
		pthread_create(&tab[index], NULL, ft_1, &timet);
		usleep(25);
		index++;
	}
	for (int i = 0;i < num_of_philo; i++)
		pthread_join(tab[i], NULL);
}
