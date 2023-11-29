#include "microshell.h"
#include <stdio.h>

int err(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	return 1;
}

int cd(char **argv, int i)
{
	if (i != 2)
		return err("error: cd: bad arguments\n");
	if (chdir(argv[i]) == -1)
		return err("error: cd: cannot change directory to "), err(argv[i]), err("\n");
	return 0;
}

int exec(char **argv, char **env, int i)
{
	int fd[2];
	int status;
	int has_pipe = argv[i] && strcmp(argv[i], "|") == 0;

	if (has_pipe && pipe(fd) == -1)
		return err("error: fatal\n");

	int pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return err("error:fatal\n");
		execve(*argv, argv, env);
		return err("error: cannot execute "), err(*argv), err("\n");
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0)) == -1 || close(fd[0]) == -1 || close(fd[1] == -1))
		return err("error: fatal\n");
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **env)
{
	int status = 0;
	int i = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[i++])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exec(argv, env, i);
		}
	}
	return status;
}
