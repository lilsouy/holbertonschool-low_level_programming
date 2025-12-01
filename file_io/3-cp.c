#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
	* print_error_exit - print error message and exit with code
	* @code: exit code
	* @msg: message to print
	* @file: file name (if needed)
	*/
void print_error_exit(int code, const char *msg, const char *file)
{
	if (file)
		dprintf(STDERR_FILENO, msg, file);
	else
		dprintf(STDERR_FILENO, "%s", msg);
	exit(code);
}

/**
	* main - copy content of one file to another
	* @argc: argument count
	* @argv: argument vector
	*
	* Return: 0 on success, exits on failure
	*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[BUF_SIZE];

	if (argc != 3)
		print_error_exit(97, "Usage: cp file_from file_to\n", NULL);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	if (close(fd_from) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", NULL);
	if (close(fd_to) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", NULL);

	return (0);
}

