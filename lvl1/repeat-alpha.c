#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	if (argc == 2)
	{
		char * str = argv[1];
		while (*str)
		{
			i = 0;
			if ((*str >= 65 && *str <= 90))
			{
				while (i <= *str - 65)
				{
					write(1, str, 1);
					i++;
				}
			}
			else if (*str >= 97 && *str <= 122)
			{
				while (i <= *str - 97)
				{
					write(1, str, 1);
					i++;
				}
			}
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
