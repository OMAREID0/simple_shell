#include "main.h"

/**
 * ch_- - Change the current working directory to the previuos.
 * @head: A pointer to the head of a directory history linked list.
 * @curren_dir: pointer to the destination directory.
 *
 * Return: 0 on success.
 */
int ch_previous(dir_c **head, char *current_dir)
{
	if ((*head)->next)
	{
		if (chdir((*head)->next->dir) != 0)
			perror("cd: ");
		else
		{
			if (getcwd(current_dir, 1024) != NULL)
			{
				insertc_dir(head, current_dir);
				if (*head == NULL)
					return (0);
				printf("%s\n%s", (*head)->dir, (*head)->dir);
			}
		}

	}
	else
		printf("cd: OLDPWD not set\n");
	return (0);
}
