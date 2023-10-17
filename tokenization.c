#include "main.h"
/**
 * tokenization - Tokenize the input command and exexute it.
 * @command: The input command to tokenize and execute.
 * @head:
 * @argv: Array of arguments.
 *
 * Return: return 0on success, -1 for errors.
 */
int tokenization(char *command, dir_c **head, char **argv)
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
		return (chdirf(argvec, arg_count, head));
	exit_status(argvec, *head);
	path = "/bin/";
	full_path = malloc(strlen(path) + strlen(argvec[0]) + 1);
	strcpy(full_path, path);
	strcat(full_path, argvec[0]);

	if (execute(full_path, argvec) == -1)
	{
		if (full_path[5] == '/')
		{
			printf("bash: %s: No such file or directory\n", full_path);
		}
		else
		{
			printf("%s: 1:", argv[0]);
			printf(" %s: not found\n", command);
		}
	}
	free(full_path);
	return (0);
}
