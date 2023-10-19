#include "main.h"

/**
 * exit_status - Exit the program with a specific status code.
 * @compare: An array of strings representing the command and arguments.
 * @head: A pointer to the head of the directory history linked list.
 *
 * Description: If the command is "exit", the function frees the directory
 * history and exits the program with the specified status code. The function
 * also frees the dir_c structure.
 *
 * Return: The exit status code.
 */
int exit_status(char **compare, dir_c *head)
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

	return exit_code;
}
