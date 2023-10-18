#include "main.h"

/**
 * ch_home - Change the current working directory to `HOME'
 *
 * Return: 0.
 */
int ch_home(void)
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

