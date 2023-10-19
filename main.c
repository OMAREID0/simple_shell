#include "main.h"
/**
 * main - simple shell project
 * @argc: number of argument pass to program
 * @argv: array of arguments.
 *
 * Return: return 0 when exit.
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	dir_c *head = NULL;
	int num_op = 0;
	int x = 1;

	while (x && argc)
	x = _main(0, command, &head, &num_op, argv);
	return (0);
}
