/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:13:27 by dclark            #+#    #+#             */
/*   Updated: 2021/07/21 16:38:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_H
# define PH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/*
** Status of philo: 
** 0 = DEAD
** 1 = EAT
** 2 = SLEEP
** 3 = THINK
*/

/*
** philo:
** 	forks[2]:
** 		each forks have a value :
** 		-1 if the philo do not have one.
** 		forks_ID >= 0 if he has one
**	satiate:
**		the number of time he need to eat before fullness (it decrement)
*/

/*
** fork:
** 	status:
** 		0: free
**		1: taken
**	ID:
**		ID number of the fork to distinguish each over
*/

# define PH_DEAD 0
# define PH_EAT 1
# define PH_SLEEP 2
# define PH_THINK 3
# define FK_FREE 0
# define FK_TAKEN 1
# define ARG_EAT 3
# define ARG_SLEEP 4
# define ARG_DEAD 2
# define ARG_PHILO 1
# define ARG_SATIA 5

typedef struct s_fork {
	int	ID;
	int	status;
}				t_fork;

typedef struct s_philo {
	int	status;
	int	time_start;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_bfor_death;
	int	forks[2];
	int	satiate;
}				t_philo;

typedef struct s_master {
	int			num_philo;
	t_philo		*philos;
	t_fork		*forks;
	pthread_t	*thread_philo;
	pthread_t	*thread_fork;
}				t_master;

int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

int		check_data(int ac, char **av);
void	taking_data(int ac, char **av, t_master *master);
void	print_philo(t_philo *philo);
void	*philo_life(void);


#endif
