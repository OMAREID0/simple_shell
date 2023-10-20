#include "main.h"

/**
 * ch_syntax - Change the current working directory based on user input.
 * @p: The destination directory in square brackets.
 * @head: A pointer to the head of a directory history linked list.
 * @current_dir: Pointer to the directory to store.
 *
 * Return: Always returns (0).
 */
int ch_syntax(char *p, dir_c **head, char *current_dir)
{
	if (chdir(p) != 0)
	{
		perror("cd: ");
	}
	else
	{
		if (getcwd(current_dir, 1024) != NULL)
		{
			insertc_dir(head, current_dir);
		}
		if (*head == NULL)
			return (0);
		printf("%s", (*head)->dir);
	}
	return (0);
}
