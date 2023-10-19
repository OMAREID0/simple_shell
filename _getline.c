#include "main.h"

/**
 * _getline - function read STDIN and store it in buffer
 * @fd: file discreptor
 * @head: pointer to diectories history.
 *
 * Return: return pointer to the buffer.
 */
char *_getline(int fd, dir_c *head)
{
	int i, bytes_read, index = 0;
	char current_char;
	static char buffer[MAX_LINE_LENGTH];
	static int eof_flag;

	for (i = 0; i < MAX_LINE_LENGTH; i++)
		buffer[i] = '\0';
	while (1)
	{
		if (index >= MAX_LINE_LENGTH - 1)
			break;
		bytes_read = read(fd, &current_char, 1);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
		{
			eof_flag = 1;
			break;
		}
		if (current_char == '\n')
			break;
		buffer[index++] = current_char;
	}
	if (eof_flag == 1)
	{
		free_dir(head);
		exit(0);
	}
	if (!index)
		return (NULL);
	return (buffer);
}
