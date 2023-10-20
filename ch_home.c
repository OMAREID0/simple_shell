#include "main.h"

/**
 * ch_home - Change the current working directory to HOME.
 * @head: Pointer to the directory history.
 * @current_dir: Pointer to the directory that will be stored in the history.
 *
 * Return: 0.
 */
int ch_home(dir_c **head, char *current_dir)
{
	chdir("/home");
	if (getcwd(current_dir, 1024) != NULL)
	{
		insertc_dir(head, current_dir);
	}
	if (*head == NULL)
		return (0);
	printf("%s", (*head)->dir);
	return (0);
}
