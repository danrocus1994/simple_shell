#include "shell_libs.h"
#include <sys/wait.h>

int runchildproc(char **process, int time, char *context)
{
	pid_t ch_pid;
	int status;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
	}
	if (ch_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		run_command(process, context);
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("I'am your father\n");
	}
	(void) time;
	return (0);
}
