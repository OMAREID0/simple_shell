#include "main.h"

/**
 * _strcat - Concatenates two arrays
 * @dest: Destination array to concatenate to
 * @src: Source array to concatenate from
 *
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;
	int i;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}

	for (i = 0; i < src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + src_len] = '\0';

	return (dest);
}
/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Negative if s1 is less than s2, positive if s1 is greater than s2,
 *         and 0 if s1 is equal to s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
	s1++;
	s2++;
	}
	return ((int)(*s1) - (int)(*s2));
}

/**
 * _strcpy - Copies a string `src' to `dest'.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
/**
 * _strdup - Duplicates a string `src'.
 * @src: The source string.
 *
 * Return: The pointer to the coppy in heap.
 */
char *_strdup(char *origin)
{
	int i;
	char *coppy;

	for (i = 0; origin[i]; ++i)
		;
	coppy = (char *)malloc(i + 1);
	if (!coppy)
		return (NULL);
	for (++i; i >= 0; i--)
		coppy[i] = origin[i];
	return (coppy);
}

