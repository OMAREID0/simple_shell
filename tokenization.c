#include "main.h"

/**
 * tokenization - Tokenize the input command and execute it.
 * @command: The input command to tokenize and execute.
 *
 * Return: 0 on success, -1 for errors.
 */
int tokenization(char *command,char **argv, int num_op)
{	
	char *argvec[MAX_ARGS];
	int arg_count = 0;
	char *path, *full_path, *token;
	
	if (command[0] == '/' && strlen(command) > 5)
		command += 5;
	token = strtok(command, " ");
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
		if(full_path[5] == '/')
			printf("bash: %s: No such file or directory\n", full_path);
		else
		{
			printf("%s: %d:", argv[0], num_op);
			printf("%s: not found\n", command);
		}
	}
	free(full_path);
	return (0);
}
