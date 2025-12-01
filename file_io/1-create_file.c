#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
	* create_file - creates a file and writes text_content to it
	* @filename: name of the file to create
	* @text_content: NULL-terminated string to write to the file
	*
	* Return: 1 on success, -1 on failure
	*/
int create_file(const char *filename, char *text_content)
{
	int fd, w;
	size_t len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		w = write(fd, text_content, len);
		if (w != (int)len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

