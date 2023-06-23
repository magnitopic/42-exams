#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *str = argv[1];
		while (str[i] == ' ' || str[i] == 11)
			i++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == 11)
			{
				while (str[i] == ' ' || str[i] == 11)
					i++;
				write(1, " ", 1);
			}
			else
			{
				write(1, &str[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}	
