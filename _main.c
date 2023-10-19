#include "main.h"

/**
 * @fd: file descriptor to user input.
 * @command: command to execute.
 * @head: pointer to directories history.
 * op:number of commands entered.
 * argv:pointer argument veector of `main'.
 *
 * Retourn:0.OR 1 if '/n' input by user.
 */
int _main(int fd, char *command, dir_c **head, int *num_op, char **argv)
{
	while (1)
	{
		if (isatty(fd))
		{
			printf("$ ");
			fflush(stdout);
		}
		command = _getline(fd, *head);
		if (!command)
		return (1);
		num_op++;
		tokenization(command, head, argv, *num_op);
	}
	return (0);
}
