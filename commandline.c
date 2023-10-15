#include "main.h"
char **narray(char *buffer, size_t limit)
{
    size_t len;
    char **strings = NULL;
    size_t nstrings = 0;

    for (len = 0; len < limit; len++)
      {
        if (buffer[len] == '\n')
	  {
            nstrings++;
	  }
      }

   
    strings = (char **)malloc((nstrings + 1) * sizeof(char *)); 
    if (!strings)
    {  
      return NULL;
    }

    size_t start = 0;
    size_t stringCount = 0;

    for (len = 0; len < limit; len++)
      {
        if (buffer[len] == '\n')
	  {
            strings[stringCount] = (char *)malloc(len - start + 1);
            if (strings[stringCount] == NULL)
	      {
                for (size_t i = 0; i < stringCount; i++)
		  {
                    free(strings[i]);
		  }
                free(strings);
                return NULL;
	      }
            memcpy(strings[stringCount], buffer + start, len - start);
            strings[stringCount][len - start] = '\0';
            start = len + 1;
            stringCount++;
	  }
      }
    strings[nstrings] = NULL;

    return strings;
}
