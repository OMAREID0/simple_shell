#include "main.h"
#include <stdlib.h>

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
