#include "shell_libs.h"
/**
 *main - shell main
 *@argc: args count
 *@argv: args
 *@envp: environment variables
 *Return: 0 if succed
 */
int main(int argc, char **argv, char **envp)
{
	char *line, *prompt, hostname[100];
	(void) argc;
	(void) argv;
	prompt = "\033[34;1m";
	size_t cch;
	line = malloc(1024);
	get_env("USER", envp, &prompt);
	gethostname(hostname, 100);
/*	printf("host: %s\n", hostname);*/
	prompt = str_concat(prompt, "@");
	prompt = str_concat(prompt, hostname);
	prompt = str_concat(prompt, "\033[0m:\033[36;1m~");
	get_env("PWD", envp, &prompt);
	prompt = str_concat(prompt, "\033[0m");

	while (1)
	{
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			printf("%s", line);
		}
	}
	return (0);
}
