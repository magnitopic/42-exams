#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char value;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			value = argv[1][i++];
			int j = 0;
			if ((value >= 65 && value <= 90))
			{
				while ((value - 65) > j++)
					write(1, &value, 1);
			}
			if ((value >= 97 && value <= 122))
			{
				while ((value - 97) >= j++)
					write(1, &value, 1);
			}
			else
				write(1, &value, 1);
		}
	}
	return (0);
}
