#include <stdio.h>

int	ft_atoi(const char *str)
{
	int num = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	num *=sign;
	return (num);
}

int	main(int argc, char **argv)
{
	printf("%d",ft_atoi("-24"));
	return (0);
}
