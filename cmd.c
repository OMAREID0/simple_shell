#include "main.h"

/**
 * cmd_to_list - construct a linked list of tokenized commands
 * @cmd: the command to parse
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return a
 * pointer to the head of the new list.
 */
cmdlist_t *cmd_to_list(const char *cmd)
{
	cmdlist_t *head = NULL;
	size_t count;
	char *split = _strdup(cmd);

	if (!split)
		return (NULL);

	count = split_cmd(split);

	if (!_cmd_to_list(&head, split, count))
	{
		free_cmdlist(&head);
		return (NULL);
	}
	free(split);

	return (head);
}


/**
 * _cmd_to_list - construct a linked list of tokenized commands (helper)
 * @tailptr: pointer to the tail of the command list
 * @split: a line split with null bytes on separators
 * @count: the number of commands contained in split
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return a
 * pointer to the tail of the new list.
 */
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count)
{
	cmdlist_t *tail;

	if (!count)
		return (*tailptr);

	tail = add_cmd_end(tailptr, split);
	if (!tail)
		return (NULL);

	while (*split++)
		;

	return (_cmd_to_list(&tail, split, count - 1));
}

/**
 * add_cmd_end - add a command at the end of the list
 * @headptr: a pointer to the address of the first list node
 * @cmd: the cmd to add to the list
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the new node.
 */
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd)
{
	cmdlist_t *new;

	if (!headptr)
		return (NULL);
	if (*headptr)
		return (add_cmd_end(&((*headptr)->next), cmd));

	new = malloc(sizeof(cmdlist_t));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->tree = NULL;

	new->tokens = tokenize(cmd);
	if (!new->tokens)
	{
		free(new);
		return (NULL);
	}
	*headptr = new;

	return (new);
}


/**
 * del_cmd - remove a command from a command list
 * @headptr: the first node
 * @index: argument passed
 * Return: address of deleted node
 */
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index)
{
	cmdlist_t *old;

	if (!(headptr && *headptr))
		return (NULL);
	if (index)
		return (del_cmd(&((*headptr)->next), index - 1));

	old = *headptr;
	*headptr = (*headptr)->next;
	free_cmdtree(&(old->tree));
	free_tokens(&(old->tokens));
	free(old);

	return (old);
}


/**
 * pop_cmd - remove a node and retrieve it's tokens
 * @headptr: the first node
 * Return: command tokens
 */
char **pop_cmd(cmdlist_t **headptr)
{
	cmdlist_t *pop;
	char **tokens;

	if (!(headptr && *headptr))
		return (NULL);

	pop = *headptr;
	tokens = pop->tokens;
	*headptr = (*headptr)->next;

	free_cmdtree(&(pop->tree));
	free(pop);

	return (tokens);
}


/**
 * free_cmdlist - free a linked list and and set head to NULL
 * @headptr: the first node
 */
void free_cmdlist(cmdlist_t **headptr)
{
	if (headptr && *headptr)
	{
		free_cmdlist(&((*headptr)->next));
		free_cmdtree(&((*headptr)->tree));
		free_tokens(&((*headptr)->tokens));
		free(*headptr);
		*headptr = NULL;
	}
}

/**
 * cmd_to_tree - construct a binary tree of commands
 * @tokens: the command to parse
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the root of the new tree
 */
cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	return (NULL);
}

/**
 * free_cmdtree - free a binary tree and and set root to NULL
 * @rootptr: pointer
 * Return: NULL
 */
void free_cmdtree(cmdtree_t **rootptr)
{
	if (rootptr && *rootptr)
	{
		free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->failure));
		(*rootptr)->tokens = NULL;
		(*rootptr) = NULL;
	}
}

