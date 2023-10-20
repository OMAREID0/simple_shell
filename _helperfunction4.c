#include "main.c"

/**
 * _num_to_str - converts number to string
 * @buf: string
 * @n: number passed
 */
static void _num_to_str(char **buf, size_t n)
{
	if (n > 9)
		_num_to_str(buf, n / 10);
	**buf = '0' + n % 10;
	*buf += 1;
	**buf = '\0';
}

/**
 * num_to_str - converts number to string
 * @n: number passed
 * Return: pointer to string
 */
char *num_to_str(size_t n)
{
	size_t tmp = n, len = 1;
	char *buf;

	while (tmp /= 10)
		len++;
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	_num_to_str(&buf, n);
	return (buf - len);
}

/**
 * parse - parse input
 * @info: shell information
 *
 * Description: This function expands aliases, variables, and word splitting
 *
 * Return: the final number of tokens
 */
int parse(info_t *info)
{
	char **tokens, *tok;
	size_t n = 0;
	cmdlist_t *cmd = info->commands = cmd_to_list(info->line);

	while (cmd)
	{
		remove_comments(cmd);
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_aliases(info->aliases, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_vars(info, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		tokens = cmd->tokens;
		for (tok = *tokens; tok; tok = *(++tokens))
		{
			*tokens = dequote(tok);
			free(tok);
		}
		cmd = cmd->next;
		++n;
	}
	return (n);
}

/**
  * search_path - searches for the directory with the executable program
  * @info: argument passed
  * @path: argument passed
  * Return: pointer to directory string
  */
char *search_path(info_t *info, list_t *path)
{
	char *pathname, *command = *info->tokens;
	struct stat sb;

	while (path)
	{
		if (*path->str == '\0')
			pathname = strjoin(NULL, "/", info->cwd, command);
		else
			pathname = strjoin(NULL, "/", path->str, command);
		if (stat(pathname, &sb) == 0)
		{
			if ((sb.st_mode & S_IFMT) != S_IFDIR)
				return (pathname);
		}
		free(pathname);
		path = path->next;
	}
	return (NULL);
}
