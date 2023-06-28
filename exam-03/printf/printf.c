#include <stdarg.h>
#include <unistd.h>

void put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void put_num(long long int num, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		len += write(1, "-", 1);
	}
	if (num >= base)
		put_num(num / base, base, len);
	write(1, &hex[num % base], 1);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int len = 0;

	va_start(args, str);
	while(*str)
	{
		if (*str == '%' && (*(str + 1) == 's' || *(str + 1) == 'd' || *(str + 1) == 'x'))
		{
			str++;
			if (*str == 's')
				put_str(va_arg(args, char *), &len);
			else if (*str == 'd')
				put_num((long long int)va_arg(args, int), 10, &len);
			else
				put_num((long long int)va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	return (va_end(args), len);
}

#include <stdio.h>

int main(void)
{
	printf(" - %d\n", printf("Hello%s %d %d %x", " There", -42, -89, 6463));
	printf(" - %d\n", ft_printf("Hello%s %d %d %x", " There", -42, -89, 6463));
}
