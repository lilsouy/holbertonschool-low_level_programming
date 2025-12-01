#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
	* print_error_exit - prints an error message and exits with a code
	* @code: the exit code
	* @msg: the format string for the error message
	* @file: the file name to include in the message (can be NULL)
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
	* copy_file - copies content from one file descriptor to another
	* @fd_from: file descriptor to read from
	* @fd_to: file descriptor to write to
	* @file_from: name of the source file (for error messages)
	* @file_to: name of the destination file (for error messages)
	*/
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t r, w;
	char buf[BUF_SIZE];

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
			print_error_exit(99, "Error: Can't write to %s\n", file_to);
	}
	if (r == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);
}

/**
	* main - copies content from one file to another
	* @argc: number of arguments
	* @argv: array of arguments
	*
	* Return: 0 on success
	*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

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

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	if (close(fd_from) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", NULL);
	if (close(fd_to) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", NULL);

	return (0);
}

