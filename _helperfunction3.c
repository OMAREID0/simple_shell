#include "main.h"
/**
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: the state associated with c
 */
quote_state_t quote_state(char c)
{
	if (_isspace(c))
		return (QUOTE_NONE);
	if (c == '"')
		return (QUOTE_DOUBLE);
	if (c == '\'')
		return (QUOTE_SINGLE);
	if (c == '\\')
		return (QUOTE_ESCAPE);
	return (QUOTE_WORD);
}


/**
 * quote_state_f - get the function associated with a given state
 * @s: state
 *
 * Return: the state associated with c
 */
quote_state_fp quote_state_f(quote_state_t s)
{
	switch (s)
	{
	case QUOTE_NONE:
		return (_quote_state_none);
	case QUOTE_WORD:
		return (_quote_state_word);
	case QUOTE_DOUBLE:
		return (_quote_state_double);
	case QUOTE_SINGLE:
		return (_quote_state_single);
	case QUOTE_ESCAPE:
		return (_quote_state_escape);
	}
	return (NULL);
}


/**
 * quote_state_len - get the length of a given state
 * @str: string
 * @state: state
 *
 * Return: the state associated with c
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
	return (quote_state_f(state)(str, NULL));
}

/**
 * remove_comments - remove comments (#) from a command
 * @cmd: pointer to the cmd to process
 */
void remove_comments(cmdlist_t *cmd)
{
	char **tokens, **new, *tmp;

	for (tokens = cmd->tokens; *tokens; ++tokens)
	{
		if (**tokens == '#')
		{
			tmp = *tokens;
			*tokens = NULL;
			new = arrdup(cmd->tokens);
			*tokens = tmp;
			free_tokens(&(cmd->tokens));
			cmd->tokens = new;
			free_cmdlist(&(cmd->next));
			return;
		}
	}
}

/**
 * split_cmd - split a command with NULL-bytes on unquoted semicolons
 * @cmd: the command to split
 *
 * Return: The total number of commands resulting from the split
 */
size_t split_cmd(char *cmd)
{
	size_t count = 1, state_len;
	ssize_t sep_index;
	quote_state_t state;

	do {
		while (*cmd && (state = quote_state(*cmd)) != QUOTE_NONE)
		{
			if (state & QUOTE_WORD)
			{
				state_len = _quote_state_word(cmd, NULL);
				sep_index = _strnchr(cmd, ';', state_len);
				if (sep_index != -1)
				{
					state_len = sep_index;
					*(cmd++ + state_len) = '\0';
					++count;
				}
				cmd += state_len;
			}
			else if (state & QUOTE_ESCAPE)
			{
				if (*(cmd + 1) == '\n')
					_strcpy(cmd, cmd + 2);
				else if (*(++cmd))
					++cmd;
			}
			else
			{
				cmd += quote_state_len(cmd + 1, state) + 1;
				if (*cmd && (state & (QUOTE_SINGLE | QUOTE_DOUBLE)))
					++cmd;
			}
		}
	} while (*(cmd += quote_state_len(cmd, QUOTE_NONE)));

	return (count);
}
