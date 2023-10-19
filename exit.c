#include "main.h"

/**
 * exit_status - exit the program with a specific status code.
 * @compare: An array of strings representing the command and arguments.
 * @head: A pointer to the head of the directory history linked list.
 */
void exit_status(char **compare, dir_c *head)
{
	if (_strcmp(compare[0], "exit") == 0)
	{
		free_dir(head);
		if (!compare[1])
			exit(0);
		exit(_atoi(compare[1]));
	}
}
