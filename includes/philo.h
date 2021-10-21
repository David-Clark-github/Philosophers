/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:09 by dclark            #+#    #+#             */
/*   Updated: 2021/10/21 13:30:02 by dclark           ###   ########.fr       */
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

struct s_philo {
	int 			ID;
	int				*fork_tab;
	pthread_mutex_t	*mutex_tab;
	int				fork_status[2];
	struct timeval	initial;
	struct timeval	ongoing;

int		check_data(int ac, char **av);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(const char *nptr);
void	taking_data(int ac, char **av, t_data_master *master);
void	*table_of_philo(void *arg);
void	init_data(t_data_master *master, t_philo *philo_tab);
void	philo_status(t_philo *philo, int status);
void	ft_putnbr(long nb);
void	display_time(struct timeval initial, struct timeval progress);

#endif
