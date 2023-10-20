#include "main.h"

/**
 * is_executable - Check if the file is executable.
 * @full_path: The path to the file.
 *
 * Return: 0 for success, -1 for errors.
 */
int is_executable(char *full_path)
{
	if (access(full_path, X_OK) == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
