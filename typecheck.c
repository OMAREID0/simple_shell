#include "main.h"

/**
  * _isalpha - checks if the character is alphabetic
  * @c: character to check
 * Return: If c is alphabetic, return 1. Otherwise, return 0.
  */
bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/**
  * _isalnum - checks if the character is alphanumeric
  * @c: character to check
 * Return: If c is alphanumeric, return 1. Otherwise, return 0.
  */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}

/**
  * _isdigit - checks if the character is digit
  * @c: character to check
  * Return: int
  */
bool _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
* _isident - checks if the character is a valid identifier character
* @c: character to check
* Return: If c is an identifier character, return 1. Otherwise, return 0.
*/
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}

/**
  * _isnumber - check if a string consists only of digits
  * @s: pointer to string
  * Return: true or false
  */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}

/**
 * _isquote - check if a character is a quote
 * @c: the character to check
 * Return: If c is a quote, return 1. Otherwise, return 0.
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}

/**
 * _isspace - check if a character is whitespace
 * @c: the character to check
 * Return: If c is whitespace, return 1. Otherwise, return 0.
 */
bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}

/**
 * _isspecial_double - check if a character is special inside double quotes
 * @c: the character to check
 * Return: If c is special, return 1. Otherwise, return 0.
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
