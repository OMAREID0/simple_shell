#include "main.h"

/**
 * chdirf - Change the current working directory based on user input.
 * @directory: An array of strings representing the command and arguments.
 * @n: The number of elements in the 'directory' array.
 * @head: A pointer to the head of a directory history linked list.
 *
 * Return: 0 on success, -1 on failure.
 */
int chdirf(char **directory, int n, dir_c **head)
{
	char *p = directory[1];
	char current_dir[1024];

	if (!*head)
	{
		if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		{
			insertc_dir(head, current_dir);
		}
	}

	if (n == 1)
		return (ch_home(head, current_dir));
	if (n == 2)
	{
		if (p[0] == '[' && p[strlen(p) - 1] == ']')
			return (ch_syntax(p, head, current_dir));
		else if (strcmp(directory[1], "-") == 0)
			return (ch_previous(head, current_dir));
	}
	printf("invalid syntax.Command syntax must be: cd [DIRECTORY]");
	return (0);
}
