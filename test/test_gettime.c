#include <sys/time.h>
#include <stdio.h>

typedef struct h1 {
	struct timeval horloge;
	long init;
	long ongoing;
	long res;
}				h1;


int main(int ac, char **av)
{
	struct timeval time;
	//START H1
	h1 horloge_1;
	gettimeofday(&horloge_1.horloge, NULL);
	horloge_1.init = horloge_1.horloge.tv_usec + (long)horloge_1.horloge.tv_sec;	
	for (int i = 0; i < 500; i++) {
	gettimeofday(&horloge_1.horloge, NULL);
	horloge_1.ongoing = horloge_1.horloge.tv_usec + (long)horloge_1.horloge.tv_sec;
	//horloge_1.ongoing - horloge_1.init;
	printf("%ld\n", ((horloge_1.ongoing - horloge_1.init + 500) / 1000));
	}
	
/*
	for (int i = 0; i < 40; i++) {
		gettimeofday(&time, NULL);
		printf("%d\n", ((time.tv_usec + 500) / 1000));
	}
	*/
}
