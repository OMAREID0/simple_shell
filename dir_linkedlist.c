#include "main.h"

/**
 * insertc_dir - Insert a new directory into the directory history linked list.
 * @head: A pointer to the head of the directory history linked list.
 * @current: The directory path to insert into the list.
 */
void insertc_dir(dir_c **head, char *current)
{
	dir_c *new_dir = malloc(sizeof(dir_c));

	if (new_dir != NULL)
	{
		new_dir->dir = strdup(current);
		new_dir->next = *head;
		*head = new_dir;
	}
	else
	{
		printf("Failed to allocate memory.\n");
	}
}
