#include <stdio.h>
#include <pthread.h>

int	tetime = 5;
int	bin = 0;

pthread_mutex_t mutex;

void	*func()
{
	pthread_mutex_lock(&mutex);
	if (bin == 0)
	{
		bin = 1;
		printf("tetime = %d\n", tetime);
		tetime--;
	}
	else
		bin = 1;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t p1;
	pthread_create(&p1, NULL, func, NULL);
}
