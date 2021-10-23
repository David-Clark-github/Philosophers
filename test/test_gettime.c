#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
typedef struct h1 {
	struct timeval horloge;
	struct timeval init;
	struct timeval ongoing;
	long res;
}				h1;

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_print(str[i]);
}

void	ft_putnbr(long nb)
{
	if (nb < 10)
		ft_print(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	time_passed(struct timeval init, int ID, int state)
{
	struct timeval ongoing;

	gettimeofday(&ongoing, NULL);
	long res_sec = ongoing.tv_sec - init.tv_sec;
	int	res_usec = ongoing.tv_usec - init.tv_usec;
	if (res_usec < 0)
	{
		res_usec = 1000000 + res_usec;
		res_sec--;
	}
	if (state == 1)
		printf("%ld.%dms %d has taken a fork\n", res_sec, (res_usec + 500) / 1000, ID);
	else if (state == 2)
		printf("%ld.%dms %d is eating\n", res_sec, (res_usec + 500) / 1000, ID);
	else if (state == 3)
		printf("%ld.%dms %d is sleeping\n", res_sec, (res_usec + 500) / 1000, ID);
	else if (state == 4)
		printf("%ld.%dms %d is thinking\n", res_sec, (res_usec + 500) / 1000, ID);
	else
		printf("%ld.%dms %d died\n", res_sec, (res_usec + 500) / 1000, ID);
}
void	time_to_passe(int adding, struct timeval *ongoing, struct timeval prog)
{
	struct timeval loop;
	int		res_usec;
	long	res_sec;

	res_sec = ongoing->tv_sec;
	res_usec = ongoing->tv_usec;
	res_usec += (adding * 1000);
	if ((res_usec += 500) / 1000 > 1000000)
	{
		res_sec++;
		res_usec -= 1000000;
	}
	//gettimeofday(&ongoing, NULL);
	while (ongoing->tv_sec < res_sec || ongoing->tv_usec < res_usec)
		gettimeofday(ongoing, NULL);
	time_passed(prog, 5, 1);
}

int main(int ac, char **av)
{

	struct timeval prog;
	struct timeval ongoing;
	gettimeofday(&prog, NULL);
	gettimeofday(&ongoing, NULL);
	for (int i = 0; i < 5; i++)
	{
		time_to_passe(200, &ongoing, prog);
		time_passed(prog, (i % 11), (i % 5));
	}
	/*
	//START H1
	h1 horloge_1;
	gettimeofday(&horloge_1.horloge, NULL);
	horloge_1.init = horloge_1.horloge;	
	for (int i = 0; (horloge_1.ongoing.tv_sec - horloge_1.init.tv_sec) != 1; i++) {
	gettimeofday(&horloge_1.horloge, NULL);
	horloge_1.ongoing = horloge_1.horloge;
	//horloge_1.ongoing - horloge_1.init;
	printf("%ld.%dms\n",horloge_1.ongoing.tv_sec - horloge_1.init.tv_sec, 
			(horloge_1.ongoing.tv_usec - horloge_1.init.tv_usec) / 1000);
	*/
	/*
	ft_putnbr((horloge_1.ongoing - horloge_1.init + 500) / 1000);
	ft_str("ms");
	ft_print('\n');
	*/
/*
	for (int i = 0; i < 40; i++) {
		gettimeofday(&time, NULL);
		printf("%d\n", ((time.tv_usec + 500) / 1000));
	}
	*/
}
