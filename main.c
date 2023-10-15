#include "main.h"

int main(int argc, char *argv[])
{
	int reaad;
	char *command = NULL;
	size_t len;
	char buffer[4096];
	size_t r;
	char **commands;
	if (isatty(STDIN_FILENO))
	{
		do {
			printf("($)");
			if (argc > 1)
			{
				command = argv[1];
			}
			else
			{
				reaad = getline(&command, &len, stdin);
				if (reaad == -1)
				{
					perror("line can not be read");
					return (1);
				}
				command[strlen(command) - 1] = '\0';
			}
			tokenization(command);
		} while (argc <= 1);
	}
	else
	{

		while((r = read(STDIN_FILENO, buffer,sizeof(buffer))) >0)
			;
		commands = narray(buffer, r);
		printf("%s", commands[0]);
		tokenization_non(commands);
	}
	return (0);
}
