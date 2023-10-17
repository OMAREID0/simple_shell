#include "main.h"

/**
 * execute - Execute a command with specified arguments.
 * @full_path: The full path to the executable
 * @argvec: An array of command arguments.
 *
 * Return: 0 on success, -1 for errors.                                                                              
 */
int execute(char *full_path, char *argvec[])
{
	pid_t cpid;
	int status = 0;

	if (is_executable(full_path) == -1)
	{
		return (-1);
	}
	cpid = fork();
	if (cpid == -1)
		exit(0);
	else if (cpid == 0)
	{
		execve(full_path, argvec, environ);
		perror("execve failed");
		exit(1);
	}
	else
	{
		waitpid(cpid, &status, 0);
		if (!WIFEXITED(status))
			printf("Child process exited abnormally.\n");
	}
	return (0);
}
