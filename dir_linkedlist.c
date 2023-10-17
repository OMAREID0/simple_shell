#include "main.h"
void insertc_dir(dir_c **head, char *current)
{
    dir_c *new_dir = malloc(sizeof(dir_c));
    new_dir->dir = strdup(current);
    new_dir->next = *head;
    *head = new_dir;
}
