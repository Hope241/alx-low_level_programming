#include "main.h"
#include <stdio.h>

/**
 *check_file - checks if files can be opened.
 *@from: input file descriptor.
 *@to: output file descriptor.
 *@args: arguments vector.
 *Return: no return.
 */
void check_file(int from, int to, char *args[])
{
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", args[1]);
		exit(98);
	}

	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", args[2]);
		exit(99);
	}
}

/**
 *main - check the code for Holberton School students.
 *@argc: number of arguments.
 *@argv: arguments vector.
 *Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, close_err;
	ssize_t read_chars, write_chars;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_file(from_fd, to_fd, argv);

	read_chars = 1024;
	while (read_chars == 1024)
	{
		read_chars = read(from_fd, buffer, 1024);
		if (read_chars == -1)
			check_file(-1, 0, argv);
		write_chars = write(to_fd, buffer, read_chars);
		if (write_chars == -1)
			check_file(0, -1, argv);
	}

	close_err = close(from_fd);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}

	close_err = close(to_fd);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}

	return (0);
}
