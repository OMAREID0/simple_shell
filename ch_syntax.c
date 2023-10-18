#include "main.h"

/**
 * chdirf - Change the current working directory based on user input.
 * @p: the directory between [].
 * @head: A pointer to the head of a directory history linked list.
 *
 * Return: 0.
 */
void ch_syntax(char *p, dir_c **head)
{
	p[strlen(p) - 1] = '\0';
		if (chdir(++p) != 0)
		{
			perror("cd: ");
		}
		else
		{
			if (getcwd(current_dir, sizeof(current_dir)) != NULL)
			{
				insertc_dir(head, current_dir);
			}
			if (*head == NULL)
				return (0);
			printf("%s", (*head)->dir);
		}
	return (0);
}
