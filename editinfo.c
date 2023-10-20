#include "main.h"

/**
 * init_info - initialize shell info
 * @argc: the arg count
 * @argv: the arg values
 * Return: pointer to the info
 */
info_t *init_info(int argc, char **argv)
{
	static info_t info;
	char *error = NULL;

	info.argc = argc;
	info.argv = argv;
	info.fileno = STDIN_FILENO;
	if (argc > 1)
	{
		info.file = argv[1];
		info.fileno = open(info.file, O_RDONLY);
		if (info.fileno == -1)
		{
			error = strjoin(NULL, " ", "Can't open", info.file);
			perrorl_default(*argv, info.lineno, error, NULL);
			free(error);
			info.status = 127;
			exit(free_info(&info));
		}
	}
	info.interactive = isatty(info.fileno);
	info.pid = getpid();
	info.cwd = getcwd(NULL, 0);
	info.env = env_to_dict(environ);
	return (&info);
}


/**
 * free_info - free and nullify dynamically allocated info
 * @info: pointer to the info
 * Return: current exit status
 */
int free_info(info_t *info)
{
	free(info->line);
	info->line = _getline(-1);
	free_tokens(&info->tokens);
	free(info->cwd);
	info->cwd = NULL;
	free(info->exe);
	info->exe = NULL;
	free_dict(&info->env);
	free_list(&info->path);
	free_dict(&info->aliases);
	free_cmdlist(&info->commands);
	return (info->status);
}

/**
 * read_input - get input
 * @info: shell information
 *
 * Return: line size
 */
bool read_input(info_t *info)
{
	char *line = NULL, *temp = NULL;

	if (info->interactive)
		write(STDERR_FILENO, "$ ", 2);

	info->lineno += 1;
	while (_read_input(&info->line, info->fileno) &
		(QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
	{
		temp = line;
		line = strjoin(NULL, "", temp, info->line);
		free(temp);
		free(info->line);
		if (info->interactive)
			write(STDERR_FILENO, "> ", 2);
		info->lineno += 1;
	}
	if (line)
	{
		temp = info->line;
		info->line = strjoin(NULL, "", line, temp);
		free(temp);
		free(line);
	}
	return (info->line);
}


/**
 * _read_input - read a single line
 * @lineptr: line buffer
 * @fd: file descriptor to read from
 *
 * Return: ending quote state
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	char *line = *lineptr = _getline(fd);
	static quote_state_t state = QUOTE_NONE;
	size_t index = 0;

	if (line)
	{
		switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
		{
		case QUOTE_DOUBLE:
		case QUOTE_SINGLE:
			do {
				index += quote_state_len(line + index, state);
				if (line[index] == '\0')
					continue;
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
					index += 1;
				/* fall through */
		case 0:
				state = quote_state(line[index]);
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
					index += 1;
			} while (line[index]);
		}
	}
	return (state);
}
