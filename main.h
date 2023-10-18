#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_ARGS 10

extern char **environ;
typedef struct directories
{
	char *dir;
	struct directories *next;
} dir_c;


/**
 * main functions
 */

int is_executable(char *full_path);
int execute(char *full_path, char *argvec[]);
int tokenization(char *command, dir_c **head, char **argv);
int ch_previous(dir_c **head,char *current_dir);
int ch_syntax(char *p, dir_c **head, char *current_dir);
void insertc_dir(dir_c **head, char *current);
int ch_home(dir_c **head, char *curreant_dir);
void free_dir(dir_c *head);
int chdirf(char **directory, int n, dir_c **head);
void exit_status(char **compare, dir_c *head);
#endif
