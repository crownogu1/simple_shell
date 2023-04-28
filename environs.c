#include "main.h"

/**
  * _getenv - Gets an environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i] != NULL)
		{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			env_var = _strdup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
  * _print_env - Prints the environment built-in
  *
  * Return: Nothing to returns
  */
void _print_env(void)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}
