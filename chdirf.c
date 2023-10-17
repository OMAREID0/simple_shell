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
	{
		chdir("/home");
		if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		{
			insertc_dir(head, current_dir);
		}

		if (*head == NULL)
			return (0);
		printf("%s", (*head)->dir);
		return (0);
	}

	if (n == 2)
	{
		if (p[0] == '[' && p[strlen(p) - 1] == ']')
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
		}
		else if (strcmp(directory[1], "-") == 0)
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
	return (0);
}
