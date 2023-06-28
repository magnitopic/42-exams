#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i = 0;
	char character;
	char *buffer = malloc(2147483647);

	if (BUFFER_SIZE < 1)
		return (free(buffer), NULL);
	while (read(fd, &character, BUFFER_SIZE / BUFFER_SIZE) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break;
	}
	buffer[i] = '\0';
	if (i == 0)
		return (free(buffer), NULL);
	return buffer;
}

