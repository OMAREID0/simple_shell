#include "main.h"

int main(int argc, char *argv[])
{
	int reaad, num_op = 0;
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
			num_op++;
			tokenization(command, argv, num_op);
		} while (argc <= 1);
	}
	else
	{

		while((r = read(STDIN_FILENO, buffer,sizeof(buffer))) >0)
			;
		command = &buffer;
		tokenization_non(commands);
	}
	return (0);
}
