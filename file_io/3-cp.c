#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
	* exit_with_error - Prints an error message and exits with a code
	* @code: Exit code
	* @msg: Error message
	* @file: File name or file descriptor
	*/
void exit_with_error(int code, char *msg, char *file)
{
	dprintf(2, "Error: %s %s\n", msg, file);
	exit(code);
}

/**
	* copy_file - Copies the content of file_from to file_to
	* @file_from: Source file
	* @file_to: Destination file
	*/
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r_bytes, w_bytes;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		exit_with_error(98, "Can't read from file", (char *)file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		exit_with_error(99, "Can't write to", (char *)file_to);
	}

	while ((r_bytes = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			exit_with_error(99, "Can't write to", (char *)file_to);
		}
	}

	if (r_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		exit_with_error(98, "Can't read from file", (char *)file_from);
	}

	if (close(fd_from) == -1)
		exit_with_error(100, "Can't close fd", "fd_from");
	if (close(fd_to) == -1)
		exit_with_error(100, "Can't close fd", "fd_to");
}

/**
	* check_args - Validates program arguments
	* @argc: Argument count
	*/
void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
	* main - Entry point. Copies content from one file to another.
	* @argc: Argument count
	* @argv: Argument vector
	*
	* Return: 0 on success
	*/
int main(int argc, char *argv[])
{
	check_args(argc);
	copy_file(argv[1], argv[2]);
	return (0);
}

