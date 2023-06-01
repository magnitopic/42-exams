#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int number;

	if (argc == 2)
	{
		i = 0;
		number = atoi(argv[1]);
		while (number >= ++i)
		{
			if (!(number % i))
			{
				printf("%d", i);
				if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
