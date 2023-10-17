#include "main.h"

int main(int argc, char *argv[])
{
	int reaad, r, num_op = 0;
	char buffer[1024], *command = NULL;
	size_t len;
	dir_c *head = NULL;

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
			tokenization(command, &head, argv, num_op);
		} while (argc <= 1);
	}
	else
	{
		r = read(STDIN_FILENO, buffer, sizeof(buffer));
		buffer[r - 1] = '\0';
		if (r <= 0)
		{
			perror("error reading input");
			return (-1);
		}
		tokenization(buffer, &head, argv, num_op);
	}
	return (0);
}
