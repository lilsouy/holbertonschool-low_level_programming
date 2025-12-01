#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
	* error_exit - Prints an error message and exits with a code
	* @code: exit code
	* @msg: message to print
	* @file: file name or descriptor to include
	*/
void error_exit(int code, char *msg, char *file)
{
	if (file)
		dprintf(STDERR_FILENO, msg, file);
	else
		dprintf(STDERR_FILENO, msg);
	exit(code);
}

/**
	* main - copies the content of a file to another file
	* @argc: number of arguments
	* @argv: argument vector
	*
	* Return: 0 on success, exits on failure
	*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", NULL);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL);

	return (0);
}

