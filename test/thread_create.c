#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*my_turn(void *arg)
{
	while (1) {
		sleep(1);
		printf("My turn!\n");
	}
	return NULL;
}

void	*your_turn(void *arg)
{
	while (1) {
		sleep(2);
		printf("Your turn!\n");
	}
	return NULL;
}

int main(void)
{
	pthread_t newthread1;
	pthread_t newthread2;

	pthread_create(&newthread1, NULL, my_turn, NULL);
	pthread_create(&newthread2, NULL, your_turn, NULL);
	pthread_join(&newthread1, NULL);
//	my_turn();
//	your_turn();
}
