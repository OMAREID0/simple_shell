#include "main.h"

int main(int argc, char *argv[])
{
	int reaad, i,num_op = 0;
	char *command;
	size_t len;
	char buffer[MAX_lin];
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
		r = read(STDIN_FILENO, buffer,sizeof(buffer));
		buffer[r - 1] = '\0';
		if(r <= 0)
		{
			perror("error reading input");
			return (-1);
		}
		tokenization(buffer, argv, num_op);
	}
	return (0);
}
