#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		while (*str)
		{
		if (*str >= 65 && *str <= 90)
		{
			if (*str == 'Z')
				*str = 'A';
			else
				*str+= 1;
		}
		else if (*str >= 97 && *str <= 122)
		{
			if (*str == 'z')
				*str = 'a';
			else
				*str+= 1;
		}
		write(1, str, 1);
		str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
