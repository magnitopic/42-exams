#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	argv++;
	if (argc == 2)
	{
		while (((*argv)[i] == 9 || (*argv)[i] == 32) && (*argv)[i])
			i++;
		while ((*argv)[i] != 9 && (*argv)[i] != 32 && (*argv)[i])
		{
			write(1, &(*argv)[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
