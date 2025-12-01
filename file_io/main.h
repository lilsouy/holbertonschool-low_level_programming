#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* Prototype for _putchar function */
int _putchar(char c);

/* Prototype for the read_textfile function */
ssize_t read_textfile(const char *filename, size_t letters);

#endif /* MAIN_H */

