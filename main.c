#include "main.h"

int main(int argc, char *argv[])
{
	char *command = NULL;
	dir_c *head = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout); 
		}
		command = _getline(STDIN_FILENO);
		if (!command)
		break; /* EOF signal */
		tokenization(command, &head, argv);
	}
	return 0;
}

