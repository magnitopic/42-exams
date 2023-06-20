#include <unistd.h>

int ft_strlen(char *str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}


int main(int argc, char **argv)
{
	if (argc == 4 && ft_strlen(argv[2])==1 && ft_strlen(argv[3])==1)
	{
		char *str = argv[1];
		while (*str)
		{
			if (*str == argv[2][0])
				*str = argv[3][0];
			write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
