#include "main.h"

/**
 *create_file - creates a file and writes content to it
 *@filename: name of file to create
 *@text_content: content to write to file
 *
 *Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nletters, rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters++)
	;

	rwr = write(fd, text_content, nletters);
	close(fd);

	if (rwr == -1)
		return (-1);

	return (1);
}
