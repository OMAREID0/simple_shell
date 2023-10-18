#include "main.h"

/**
 * chdirf - Change the current working directory based on user input.
 * @p: the destination directory between [].
 * @head: A pointer to the head of a directory history linked list.
 * @current_dir: pointer to the directory to store.
 * Return: 0.
 */
int ch_syntax(char *p, dir_c **head, char *current_dir)
{
	p[strlen(p) - 1] = '\0';
		if (chdir(++p) != 0)
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
