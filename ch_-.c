#include "main.h"

/**
 * chdirf - Change the current working directory to the previuos.
 * @head: A pointer to the head of a directory history linked list.
 *
 * Return: 0 on success.
 */
int ch_-(dir_c **head)
{
	if ((*head)->next)
	{
		if (chdir((*head)->next->dir) != 0)
		{
			perror("cd: ");
		}
			else if (getcwd(current_dir, sizeof(current_dir)) != NULL)
			{
				insertc_dir(head, current_dir);
			}
			if (*head == NULL)
				return (0);
			printf("%s\n%s", (*head)->dir, (*head)->dir);
			}
		}
		else
		{
			printf("cd: OLDPWD not set\n");
		}
	}
	return(0);
}
