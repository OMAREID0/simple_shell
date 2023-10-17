#include "main.h"

void termination(char *buffer, dir_c **head)
{
	int i;

	for(i = 0; buffer[i] != '\n'; ++i)
		;
	buffer[i] = '\0';
	tokenization(buffer, head);
}
