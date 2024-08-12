#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *command;
	pid_t pid;
	int status;

	while (1)
	{
	prompt();

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
	if (feof(stdin))
	{
		printf("\n");
	exit(0);
	}
	perror("fgets");
	exit(1);
	}

	size_t len = strlen(buffer);

	if (len > 0 && buffer[len - 1] == '\n')
	{
	buffer[len - 1] = '\0';
	}

	if (strlen(buffer) == 0)
	{
	continue;
	}

	pid = fork();
	if (pid < 0)
	{
	perror("fork");
	exit(1);
	}

	if (pid == 0)
	{
	execlp(buffer, buffer, (char *)NULL);
	perror(buffer);
	exit(1);
	else
	{
	do
	{
	pid = waitpid(pid, &status, WUNTRACED);
	if (pid == -1) {
	perror("waitpid");
	exit(1);
	}
	}
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	}

	return (0);
}
