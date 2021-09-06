#include <sys/time.h>
#include <stdio.h>

struct timevals {
	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
	suseconds_t  tv_usec;  /* and microseconds */
};


int main()
{
	struct timeval timevals;
	gettimeofday(&timevals, 0);
	printf("time = %ld\n", timevals.tv_sec);
}