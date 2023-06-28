#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("%s", get_next_line(fd));
	return (0);
}

