#include "main.h"

/**
 * free_dir - Free the memory associated with a linked list of directories.
 * @head: A pointer to the head of the directory history linked list.
 */
void free_dir(dir_c *head)
{
	dir_c *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->dir);
		free(current);
	}
}
