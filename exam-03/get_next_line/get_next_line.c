#include "get_next_line.h"
#include <fcntl.h>

char *get_next_line(int fd)
{
	int i = 0;
	int rd;
	char character;
	char *buffer = malloc(1000000);

	if (BUFFER_SIZE < 1)
	{
		free(buffer);
		return (NULL);
	}
	while ((rd =read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1))  > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (i == 0)
		return (free(buffer), NULL);
	return buffer;
}

int main (void)
{
	int fd =open ("get_next_line.h", O_RDONLY);
	char *test = get_next_line(fd);
	while (test)
	{
		printf("%s", test);
		test = get_next_line(fd);
	}
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return (0);
}
