#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	pid_t cp_id;
	cp_id=fork();
	if (cp_id<0)
	{
		fprintf(stderr,"Fork Failed\n");
		return 1;
	}
	else if (cp_id==0)
	{
		printf("I am child process having ID: %d\n",getpid());
		printf("My parent process is having ID: %d\n",getppid());
		execl("/bin/ls","ls","-l",NULL);
		perror("execl subroutine failed");
		exit(1);
	}
	else
	{
		wait(NULL);
		printf("I am parent process having ID: %d\n",getpid());
		printf("My child proces ID: %d\n",cp_id);
	}
	return 0;
}
