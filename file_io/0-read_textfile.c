#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
	* open_and_allocate - opens a file and allocates a buffer
	* @filename: name of the file to open
	* @buffer: pointer to store allocated buffer address
	* @letters: number of letters to read
	*
	* Return: file descriptor on success, -1 on failure
	*/
int open_and_allocate(const char *filename, char **buffer, size_t letters)
{
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	*buffer = malloc(sizeof(char) * letters);
	if (!*buffer)
	{
		close(fd);
		return (-1);
	}

	return (fd);
}

/**
	* read_and_print - reads from a file descriptor and prints to stdout
	* @fd: file descriptor to read from
	* @buffer: buffer to store read data
	* @letters: number of letters to read
	*
	* Return: number of bytes read and written, 0 on failure
	*/
ssize_t read_and_print(int fd, char *buffer, size_t letters)
{
	ssize_t r, w;

	r = read(fd, buffer, letters);
	if (r == -1)
		return (0);

	w = write(STDOUT_FILENO, buffer, r);
	if (w != r)
		return (0);

	return (r);
}

/**
	* read_textfile - reads a text file and prints it to stdout
	* @filename: name of the file
	* @letters: number of letters to read
	*
	* Return: number of bytes read and printed, 0 on failure
	*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t result;

	fd = open_and_allocate(filename, &buffer, letters);
	if (fd == -1)
		return (0);

	result = read_and_print(fd, buffer, letters);

	free(buffer);
	close(fd);
	return (result);
}

