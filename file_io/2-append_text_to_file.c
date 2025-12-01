#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
	* append_text_to_file - appends text at the end of a file
	* @filename: name of the file
	* @text_content: NULL-terminated string to add at the end of the file
	*
	* Return: 1 on success, -1 on failure
	*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0, written;

	if (filename == NULL)
	return (-1);

	/* If text_content is not NULL, calculate its length */
	if (text_content != NULL)
	{
	while (text_content[len] != '\0')
	len++;
	}

	/* Open the file for writing, do not create if it doesn't exist */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);

	if (len > 0)
	{
	written = write(fd, text_content, len);
	if (written != len)
	{
	close(fd);
	return (-1);
	}
	}

	close(fd);
	return (1);
}

