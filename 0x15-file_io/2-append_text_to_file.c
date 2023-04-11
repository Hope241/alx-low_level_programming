#include "main.h"
#define FILE_PERMS(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 *append_text_to_file - appends text to a file.
 *@filename: the name of the file to append to.
 *@text_content: the text to append to the file.
 *
 *Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, num_chars, write_result;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND, FILE_PERMS);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (num_chars = 0; text_content[num_chars]; num_chars++)
		;

		write_result = write(file_descriptor, text_content, num_chars);
		if (write_result == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);

	return (1);
}
