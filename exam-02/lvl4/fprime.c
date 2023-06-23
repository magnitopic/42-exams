#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int flag = 0;
		int num = atoi(argv[1]);
		int og_num = atoi(argv[1]);
		int i = 2;

		while (i < og_num)
		{
			if (num % i == 0)
			{
				if (flag)
					printf("*");
				num /= i;
				flag = 1;
				printf("%d", i);
			}
			else
				i++;
		}
		if (num == og_num)
			printf("%d", og_num);
	}
	printf("\n");
}
