/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:09 by dclark            #+#    #+#             */
/*   Updated: 2021/09/25 14:29:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ARG_PHILO 1
# define ARG_DIE 2
# define ARG_EAT 3
# define ARG_SLEEP 4
# define ARG_SATIA 5

typedef struct	s_data_master {
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_number;
	int				*tab_fork;
	pthread_t		*ptab;
	pthread_mutex_t	mutex;
}				t_data_master;

typedef struct	s_philo_thread {
	struct timeval	time_val;
	int				ID;
	int				fork[2];
	int				*tab_fork;
	int				state;
	pthread_mutex_t *mutex;
}				t_philo;

int		check_data(int ac, char **av);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(const char *nptr);
void	taking_data(int ac, char **av, t_data_master *master);

#endif