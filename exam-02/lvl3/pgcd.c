#include <stdio.h>
#include <stdlib.h>

int get_hcd(int min, int max)
{
	int i = min - 1;

	while (i > 0)
	{
		if (min%i==0 && max%i==0)
			return i;
		i--;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);

		if (num1 < num2)
			printf("%d", get_hcd(num1, num2));
		else
			printf("%d", get_hcd(num1, num2));
	}
	printf("\n");
	return (0);
}
