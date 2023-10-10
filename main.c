#include "main.h"

int main(int argc, char *argv[])
{
	int read;
	char *command = NULL;
	size_t len;

	do {
		printf("($)");
		if (argc > 1)
		{
			command = argv[1];
		}
		else
		{
			read = getline(&command, &len, stdin);
			if (read == -1)
			{
				perror("line can not be read");
				return (1);
			}
			command[strlen(command) - 1] = '\0';
		}
		tokenization(command);
	} while (argc <= 1);

	return (0);
}
