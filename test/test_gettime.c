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

int main(int ac, char **av)
{
	struct timeval time;
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
	/*
	ft_putnbr((horloge_1.ongoing - horloge_1.init + 500) / 1000);
	ft_str("ms");
	ft_print('\n');
	*/
	}
/*
	for (int i = 0; i < 40; i++) {
		gettimeofday(&time, NULL);
		printf("%d\n", ((time.tv_usec + 500) / 1000));
	}
	*/
}
