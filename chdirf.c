#include "main.h"

int chdirf(char **directory, int n, dir_c **head)
{
    char *q;
    char *p = directory[1];

    if (!*head)
    {
        char current_dir[1024];
        if (getcwd(current_dir, sizeof(current_dir)) != NULL)
        {
            insertc_dir(head, current_dir);
        }
    }

    if (n == 1)
    {
        chdir("/home");
        char current_dir[1024];
        if (getcwd(current_dir, sizeof(current_dir)) != NULL)
        {
            insertc_dir(head, current_dir);
        }
        if (*head == NULL)
            return 0;
        printf("%s", (*head)->dir);
        return 0;
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
                char current_dir[1024];
                if (getcwd(current_dir, sizeof(current_dir)) != NULL)
                {
                    insertc_dir(head, current_dir);
                }
                if (*head == NULL)
                    return 0;
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
                else
                {
                    char current_dir[1024];
                    if (getcwd(current_dir, sizeof(current_dir)) != NULL)
                    {
                        insertc_dir(head, current_dir);
                    }
                    if (*head == NULL)
                        return 0;
                    printf("%s\n%s", (*head)->dir,(*head)->dir);
                }
            }
            else
            {
                printf("cd: OLDPWD not set\n");
            }
        }
    }
    return 0;
}

