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

/**
 * main functions
 */
int tokenization(char *command);
int is_executable(char *full_path);
int execute(char *full_path, char *argvec[]);
int tokenization_non(char **commands);
char **narray(char *buffer, size_t limit);


#endif
