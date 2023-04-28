#include "main.h"

/**
* main - Runs a simple UNIX command interpreter.
*
* Return: 0 if success, otherwise -1.
*/

#define PROMPT "($) "
#define EXIT_SUCCESS 0
#define READLINE_ERROR -1

int main(void)
{
char *line = NULL;
size_t line_size = 0;
ssize_t line_len = 0;

while (line_len >= 0)
{
signal(SIGINT, signal_handler);
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, PROMPT, sizeof(PROMPT));
line_len = getline(&line, &line_size, stdin);
if (line_len == READLINE_ERROR)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}

int word_count = count_input(line);
if (line[0] != '\n' && word_count > 0)
{
char **tokens = tokenize(line, " \t", word_count);
int exec_flag = execBuiltInCommands(tokens, line);
if (!exec_flag)
{
char *command = find(tokens[0]);
if (command && access(command, X_OK) == 0)
exec(command, tokens);
else
perror("./hsh");
}

frees_tokens(tokens);
}
}

free(line);
return (EXIT_SUCCESS);
}
