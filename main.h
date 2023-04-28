#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

extern char **environ;
char *_getenv(const char *name);
char **tokenize(char *str, char *del, int len);
char *remove_new_line(char *str);
char *find(char *cname);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
int _atoi(char *s);
int count_input(char *str);
int count_delims(char *str, char *del);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void signal_handler(int sig_id);
void _open_help(void);
void _print_env(void);
void frees_get_env(char *env_path);
void frees_tokens(char **tokns);
void _handle_exit(char **u_tokns, char *line);
int execBuiltInCommands(char **u_tokns, char *line);
int exec(char *cname, char **opts);

#endif _MAIN_H
