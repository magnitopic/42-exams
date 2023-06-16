#include <stdio.h>

int ft_strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;
	return (count);
}

int main(void)
{
	char str[13] = "Hello There\n";
	printf("%d\n", ft_strlen(str));
	return (0);
}
