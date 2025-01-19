#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void *count_characters(void *args);

sem_t sem;

int main()
{
	pthread_t thread;
	char input[100];
	sem_init(&sem,0,1);
	printf("Main Thread: Enter a string: ");
	scanf(" %[^\n]s",input);
	if (pthread_create(&thread, NULL, count_characters, (void *)input) !=0)
	{
		perror("Failed to create thread");
		return 1;
	}
	printf("Main Thread: Running Simultaneously\n");
	pthread_join(thread, NULL);
	sem_destroy(&sem);
	return 0;
}

void *count_characters(void *args)
{
	sem_wait(&sem);
	char *input = (char *)args;
	printf("Thread: Counting Characters\n");
	printf("Thread: Number of Characters = %lu\n", strlen(input));
	sem_post(&sem);
	return NULL;
}
