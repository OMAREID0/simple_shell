#include "main.h"

char* _getline(int fd)
{	 
	int i, index = 0;
	char current_char;
	static char buffer[MAX_LINE_LENGTH];
	static int eof_flag = 0;
	int bytes_read;

	for (i = 0; i < MAX_LINE_LENGTH; i++)
	{
		buffer[i] = '\0';
	}
 
	while (1)
	{
		if (index >= MAX_LINE_LENGTH - 1)
		{
			break; 
		}
		bytes_read = read(fd, &current_char, 1);
  		if (bytes_read < 0)
		{
			perror("Error reading from file descriptor");
			return NULL;
		}

		if (bytes_read == 0)
		{
			eof_flag = 1; 
			break;
		}

		if (current_char == '\n')
		{
			break; 
        	}

		buffer[index++] = current_char;
    	}

	if (eof_flag && index == 0)
	{
		return (NULL);
	}

    	return (buffer);
}
