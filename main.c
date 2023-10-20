#include "main.h"

/**
 * main - Simple shell project
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments
 *
 * Return: 0 when exiting
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	dir_c *head = NULL;
	int num_op = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		command = _getline(STDIN_FILENO);

		if (!command)
			break;
		num_op++;
		tokenization(command, &head, argv, num_op);
		if (argc > 1000)
		{
			printf("a7a bt3ml eh");
		}
	}
	return (0);
}
