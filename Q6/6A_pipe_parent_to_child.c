#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fd[2];
	pid_t pid;
	char message[]="Hello from parent!\n";
	char buffer[100];
	if (pipe(fd)==-1)
	{
		perror("pipe failed\n");
		exit(EXIT_FAILURE);
	}
	pid=fork();
	if (pid<0)
	{
		perror("fork failed\n");
		exit(EXIT_FAILURE);
	}
	if (pid>0)
	{
		printf("This is parent process passing message to child.\n");
		close(fd[0]);
		write(fd[1],message,strlen(message)+1);
		close(fd[1]);
	}
	else
	{
		printf("This is child process receiving the message from parent.\n");
		close(fd[1]);
		read(fd[0],buffer,sizeof(buffer));
		printf("Child received: %s\n",buffer);
		close(fd[0]);
	}
	return 0;
}
