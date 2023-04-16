#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#define FILE_PERMS(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 *append_text_to_file - appends text to the end of a file
 *@filename: the name of the file
 *@text_content: the text to append to the file
 *
 *Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	size_t text_len;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(file_descriptor);
		return (1);
	}

	text_len = 0;
	while (text_content[text_len] != '\0')
		text_len++;

	bytes_written = write(file_descriptor, text_content, text_len);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
