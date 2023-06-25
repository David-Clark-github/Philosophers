/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:09 by dclark            #+#    #+#             */
/*   Updated: 2021/11/19 16:33:29 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define ARG_PHILO 1
# define ARG_DIE 2
# define ARG_EAT 3
# define ARG_SLEEP 4
# define ARG_SATIA 5

typedef struct s_philo {
	int				num_of_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				rasa;
	int				id;
	int				*fork_tab;
	pthread_mutex_t	*mutex_tab;
	pthread_mutex_t	*mutex_status;
	int				fork_status[2][2];
	int				num_of_fork;
	struct timeval	initial;
	struct timeval	ongoing;
	struct timeval	touch_death;
	int				state;
	int				*death;
	pthread_mutex_t	*mutex_death;
}				t_philo_data;

typedef struct s_data_dump {
	pthread_t		*p_tab;
	t_philo_data	*philo_data;
	int				num_of_philo;
	int				master_death;
	pthread_mutex_t	*mutex_tab;
	pthread_mutex_t	mutex_status;
	pthread_mutex_t	mutex_death;
	int				*fork_tab;
}				t_data_dump;

int		check_data(int ac, char **av);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
long	ft_atoi(const char *nptr);
int		taking_data(char **av, t_data_dump *master);
void	*table_of_philo2(void *arg);
void	init_data(int ac, char **av, t_data_dump *master, struct timeval *prog);
void	ft_putnbr(long nb);
void	time_passed(struct timeval prog, int state, t_philo_data *philo);
void	time_to_passe(int adding, struct timeval *ongoing, t_philo_data *philo);
int		check_death(t_philo_data *philo);
void	restart_death(t_philo_data *philo);
void	*kill_philo(t_philo_data *philo);
void	grid_philo(t_philo_data *philo);
void	taking_fork(t_philo_data *philo);
void	release_fork(t_philo_data *philo);

#endif
