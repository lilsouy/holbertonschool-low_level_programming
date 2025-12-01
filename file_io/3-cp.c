#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
	* main - copies the content of a file to another file
	* @argc: number of arguments
	* @argv: array of arguments
	*
	* Return: 0 on success, exit with specified codes on failure
	*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (argc != 3)
	{
	dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
	exit(97);
	}

	/* Open the source file */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}

	/* Open the destination file, create if needed, truncate if exists */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
	dprintf(2, "Error: Can't write to %s\n", argv[2]);
	if (close(fd_from) == -1)
	dprintf(2, "Error: Can't close fd %d\n", fd_from);
	exit(99);
	}

	/* Copy in chunks of 1024 bytes */
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
	n_written = write(fd_to, buffer, n_read);
	if (n_written != n_read)
	{
	dprintf(2, "Error: Can't write to %s\n", argv[2]);
	close(fd_from);
	close(fd_to);
	exit(99);
	}
	}

	if (n_read == -1)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	close(fd_from);
	close(fd_to);
	exit(98);
	}

	/* Close file descriptors and check for errors */
	if (close(fd_from) == -1)
	{
	dprintf(2, "Error: Can't close fd %d\n", fd_from);
	exit(100);
	}
	if (close(fd_to) == -1)
	{
	dprintf(2, "Error: Can't close fd %d\n", fd_to);
	exit(100);
	}

	return (0);
}

