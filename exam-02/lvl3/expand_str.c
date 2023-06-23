#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str=argv[1];
		int i = 0;
		int flag = 0;
		while (str[i] == 32 || str[i] == 11)
			i++;
		while (str[i])
		{
			if (str[i] == 32 || str[i] == 11)
			{
				while (str[i] == 32 || str[i] == 11)
					i++;
				flag = 1;
			}	
			else
			{
				if (flag)
				{					
					write(1, "   ", 3);
					flag = 0;
				}
				write(1, &str[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
