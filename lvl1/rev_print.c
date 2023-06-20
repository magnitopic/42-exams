#include <unistd.h>

int ft_strlen (char *str)
{
	int len = 0;
	while (str[len])
	{
		len++;
	}
	return len;
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		char *str = argv[1];
		int len = ft_strlen(str);
		while (len >= 0)
		{
			write(1, &str[len--], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
