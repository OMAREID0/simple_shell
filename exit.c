#include "main.h"

void exit_status(char **compare, dir_c *head)
{
	if (strcmp(compare[0], "exit") == 0)
	{	
		free_dir(head);		
		if(!compare[1])
			exit(0);
		exit(atoi(compare[1]));
	}
}

