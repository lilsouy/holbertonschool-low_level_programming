#include "main.h"

/**
	* read_textfile - reads a text file and prints it to standard output
	* @filename: the file to read
	* @letters: number of letters to read and print
	*
	* Return: the actual number of letters read and printed,
	*         or 0 if an error occurs
	*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buffer;

	if (filename == NULL)
	return (0);

	/* Open the file for reading only */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

	/* Allocate buffer to hold file content */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
	close(fd);
	return (0);
	}

	/* Read from the file */
	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
	free(buffer);
	close(fd);
	return (0);
	}

	/* Write to standard output */
	n_written = write(STDOUT_FILENO, buffer, n_read);
	if (n_written != n_read)
	{
	free(buffer);
	close(fd);
	return (0);
	}

	free(buffer);
	close(fd);
	return (n_written);
}

