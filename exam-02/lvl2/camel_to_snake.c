#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		while (*str)
		{
			if (*str >= 65 && *str <= 90)
			{
				write(1, "_", 1);
				*str += 32;
				write(1, str, 1);
			}
			else
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
