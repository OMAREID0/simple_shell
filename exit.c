#include "main.h"

/**
 * exit_status - Exit the program with a specific status code.
 * @compare: An array of strings representing the command and arguments.
 * @head: A pointer to the head of the directory history linked list.
 */
void exit_status(char **compare, dir_c *head)
{
	int exit_code = 0;

	if (_strcmp(compare[0], "exit") == 0)
	{
		free_dir(head);
		if (!compare[1])
			exit(exit_code);
		exit_code = _atoi(compare[1]);
		exit(exit_code);
	}
}
