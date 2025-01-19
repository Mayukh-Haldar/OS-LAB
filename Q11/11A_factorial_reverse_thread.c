#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>

void *calculate_factorial(void *args);
void *find_reverse(void *args);

int main(int argc, char* argv[])
{
	pthread_t thread1, thread2;
	long long num;
	printf("Main Thread: Enter a number: ");
	scanf("%lld",&num);
	if (pthread_create(&thread1, NULL, calculate_factorial, (void *)&num) != 0)
	{
		perror("Failed to create thread1.\n");
		return 1;
	}
	if (pthread_create(&thread2, NULL, find_reverse, (void *)&num) != 0)
	{
		perror("Failed to create thread2.\n");
		return 1;
	}
	void *fact_result;
	void *rev_result;
	pthread_join(thread1, &fact_result);
	pthread_join(thread2, &rev_result);
	printf("Main Thread: Factorial Result = %lld\n", (long long)fact_result);
	printf("Main Thread: Reverse Result = %lld\n", (long long)rev_result);
	return 0;
}

void *calculate_factorial(void *args)
{
	long long num=*(long long *)args;
	long long fact=1;
	for (int i=2; i<=num; i++)
	{
		fact*=i;
	}
	printf("Thread: Factorial of %lld is %lld\n",num,fact);
	return (void *)fact;
}

void *find_reverse(void *args)
{
	long long num = *(long long *)args;
	long long rev=0, m=num;
	while (num!=0)
	{
		rev=rev*10+num%10;
		num/=10;
	}
	printf("Thread: Reverse of %lld is %lld\n",m, rev);
	return (void *)rev;
}
