#include <stdio.h>

int ft_printf(const char *str, ...);

int main(void)
{
	printf(" - %d\n", printf("Hello%s %d %d %x", " There", -42, -89, 6463));
	printf(" - %d\n", ft_printf("Hello%s %d %d %x", " There", -42, -89, 6463));
}
