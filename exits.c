/**
 * handle_exit_command - Handles the built-in exit command.
 *
 * @u_tokns: The command and its arguments as an array of strings.
 * @line: The user's input line.
 */
void handle_exit_command(char **u_tokns, char *line)
{
	int status = EXIT_SUCCESS;

	if (u_tokns[1] == NULL || _strcmp(u_tokns[1], "0") == 0)
		exit(status);

	status = _atoi(u_tokns[1]);
	if (status != 0)
		exit(status);

	_puts("exit: Illegal number: ");
	_puts(u_tokns[1]);
	_puts("\n");
	exit(2);

	/* This line should be moved after the exit calls. */
	frees_tokens(u_tokns);
}

