#include "main.h"

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to concatenate.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
    int length = 0;

    while (*s != '\0')
    {
        length++;
        s++;
    }

    return length;
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

    return (int)(*s1) - (int)(*s2);
}

/**
 * _strcpy - Copy a string from source to destination.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: The pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
    char *original_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

/**
 * _strdup - Duplicate a string.
 * @origin: The source string to duplicate.
 *
 * Return: The pointer to the copy in the heap.
 */
char *_strdup(const char *origin)
{
    int i;
    char *copy;

    for (i = 0; origin[i]; ++i)
        ;
    copy = (char *)malloc(i + 1);
    if (!copy)
        return NULL;
    for (++i; i >= 0; i--)
        copy[i] = origin[i];
    return copy;
}
