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
	char *line, *prompt;
	(void) argc;
	(void) argv;
	prompt = "\033[32;1m";
	size_t cch;
	line = malloc(1024);
	get_env("USER", envp, &prompt);
	prompt = str_concat(prompt, "@ubuntu:~\033[35m");
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
