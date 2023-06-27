#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char character;
	char *buffer = malloc(1000000);

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
			return (free(buffer), NULL);
	return (buffer);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *a = get_next_line(fd);
		while (a != NULL)
		{
			printf("%s", a);
			a =  get_next_line(fd);
		}
	}
	return (0);
}

