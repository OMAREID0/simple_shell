#include "main.h"

/**
 * is_executable - check if the file is accessable ot not
 * @full_path: path of the file
 *
 * Return: Always return 0 if success, and -1 for Errors.
 */
int is_executable(char *full_path)
{
	if (access(full_path, F_OK) == -1)
	{
		perror("command not found");
		return (-1);
	}
	else
	{
		return (0);
	}
}
