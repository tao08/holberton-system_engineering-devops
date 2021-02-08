#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * infinite_while - Run an infinite while loop
 *
 * Return: 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - program that creates 5 zombie processes.
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid1;
	int status;

	while (status < 5)
	{
		pid1 = fork();
		if (pid1 == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid1 > 0)
		{
			printf("Zombie process created, PID: %u\n", pid1);
			sleep(3);
			status++;
		}
		else
			exit(0);
	}
	infinite_while();
	return (0);
}
