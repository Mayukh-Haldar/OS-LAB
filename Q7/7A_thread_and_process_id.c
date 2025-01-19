#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

void *thread_function(void *args);

pthread_t main_thread_id, new_thread_id;
pid_t main_process_id, new_process_id;

int main(int argc, char* argv[])
{
	pthread_t thread;
	main_thread_id=pthread_self();
	main_process_id=getpid();
	printf("Main Thread: Thread ID = %lu, Process ID = %d\n", main_thread_id, main_process_id);
	if (pthread_create(&thread, NULL, thread_function, NULL) !=0)
	{
		perror("Failed to create thread\n");
		return 1;
	}
	pthread_join(thread, NULL);
	return 0;
}

void *thread_function(void *args)
{
	new_thread_id=pthread_self();
	new_process_id=getpid();
	printf("New Thread: Thread ID = %lu, Process ID = %d\n", new_thread_id, new_process_id);
       	return NULL;
}

