#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *Worker(void *null) 
{
	int i;
	double result=0.0;
	for(i=0;i<1000000;i++)
	{
		result = result + (double)random();
	}
	printf("result = %e \n",result);
	pthread_exit(NULL);
}
int main () 
{
	pthread_t threads[MAX_THREADS];
	int result, num, status;

	for(num=0; num<MAX_THREADS; num++)
	{
		printf("Creating a thread\n");
		result=pthread_create(&threads[num], NULL,Worker,(void *) num);
		if(result)
		{
			perror("pthread_create");
			exit(1);
		}
	}
	for (num=0; num<MAX_THREADS; num++)
	{
		result = pthread_join( threads[num], (void **)&status);
	       if(result)
	       {
		       perror("pthread_join");
		       exit(1);
	       }
	       printf("Main: completed join with thread %d status=%d. \n", num, status);
	}
	pthread_exit(NULL);
}

