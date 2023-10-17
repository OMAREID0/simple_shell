#include "main.h"

/**
 * free_dir - Free the memory associated with a linked list of directories.
 * @head: A pointer to the head of the directory history linked list.
 */
void free_dir(dir_c *head)
{
	dir_c *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p->dir);
		free(p);
	}
}
