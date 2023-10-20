#include "main.h"

/**
  * dict_to_env - creates linked list from environment
  * @head: argument passed
  * Return: pointer to list
  */
char **dict_to_env(env_t *head)
{
	env_t *tmp = head;
	char **env;
	size_t len = 0;

	while (tmp)
		++len, tmp = tmp->next;

	env = malloc(sizeof(char *) * (len + 1));
	if (!env)
		return (NULL);

	for (len = 0; head; head = head->next)
		env[len++] = strjoin(NULL, "=", head->key, head->val);
	env[len] = NULL;

	return (env);
}

/**
  * env_to_dict - creates a list from environment
  * @env: environment passed
  * Return: head
  */
env_t *env_to_dict(char **env)
{
	env_t *head = NULL;

	if (!_env_to_dict(&head, env))
		free_dict(&head);

	return (head);
}


/**
 * _env_to_dict - turn the environment into a linked list (helper)
 * @tailptr: pointer to the tail of the list
 * @env: environment
 *
 * Return: pointer to the tail of the list
 */
env_t *_env_to_dict(env_t **tailptr, char **env)
{
	env_t *tail;
	char *env_str;
	ssize_t key_len;

	if (!*env)
		return (*tailptr);

	env_str = _strdup(*env);
	if (!env_str)
		return (NULL);

	key_len = _strchr(*env, '=');

	if (key_len == -1)
		return (NULL);

	env_str[key_len] = '\0';
	tail = add_dict_node_end(tailptr, env_str, env_str + key_len + 1);
	free(env_str);

	return (_env_to_dict(&tail, env + 1));
}

/**
  * perrorl - print a formatted message to standard error
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl(const char *msg, ...)
{
	const char *str;
	va_list context;

	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(context);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}


/**
  * perrorl_default - print a formatted message to standard error
  * @arg0: argument vector
  * @lineno: line number
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	const char *str = NULL;
	va_list ap;

	if (arg0)
		write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": ", 2);

	if (linenostr)
		write(STDERR_FILENO, linenostr, _strlen(linenostr));
	write(STDERR_FILENO, ": ", 2);

	va_start(ap, msg);
	while ((str = va_arg(ap, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(ap);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(linenostr);
}
