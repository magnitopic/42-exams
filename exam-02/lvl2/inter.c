#include <unistd.h>
#include <stdio.h>

int check_dup(char str1, char *og_str, int i)
{
	while (i >= 0)
	{
		if (str1 == og_str[i])
			return 0;
		i--;
	}
	return 1;
}

int check_strs(char str1, char *str2)
{
	while (*str2)
	{
		if (str1 == *str2)
			return 1;
		str2++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		char *str1 = argv[1];
		char *og_str = argv[1];
		char *str2 = argv[2];

		while (*str1)
		{
			if (check_dup(*str1, og_str, i - 1) && check_strs(*str1, str2))
				write(1, str1, 1);
			str1++;
			i++;
		}	
	}
	write(1, "\n", 1);
	return (0);
}
