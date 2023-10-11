#include "main.h"

int tokenization(char *command)
{
	char *argvec[MAX_ARGS];
	int arg_count = 0;
	char *path, *full_path;

	char *token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGS)
	{
		argvec[arg_count] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	argvec[arg_count] = NULL;

	if (strcmp(argvec[0], "cd") == 0)
	{
		if (arg_count > 1)
		{
			if (chdir(argvec[1]) != 0)
			{
				perror("cd failed");
			}
		}
		return (0);
	}

	if (strcmp(argvec[0], "exit") == 0)
	{
		exit(1);
	}

	path = "/bin/";
	full_path = malloc(strlen(path) + strlen(argvec[0]) + 1);
	strcpy(full_path, path);
	strcat(full_path, argvec[0]);

	if (execute(full_path, argvec) == -1)
	{
		printf("can't execute this action");
		free(full_path);
		exit(1);
	}
	free(full_path);
	return (0);
}
