#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int symbol = 1;
	int result = 0;

	while (str[i] == 15 || str[i]== 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		symbol = -1;
	}
	while (str[i] >=48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * symbol;
}

int main(void)
{
	printf("%d\n", atoi("         3344    -4aazz12"));
	printf("%d\n", ft_atoi("      3344  -4aaazz12"));
	return (0);
}
