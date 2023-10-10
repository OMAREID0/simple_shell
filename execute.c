#include "main.h"

int execute(char *full_path, char *argvec[])
{
	pid_t cpid;
	int status = 0;

	if (is_executable(full_path) == -1)
	{
		printf("can't access file");
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
