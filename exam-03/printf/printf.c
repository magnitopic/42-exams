#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void put_digit(long long int number, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*len  += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, len);
	*len += write(1, &hex[number % base], 1);
}

int ft_printf(const char *format, ... )
{
	va_list args;
	int len = 0;
	
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(args, char *), &len);
			else if (*format == 'd')
				put_digit(va_arg(args, long long int), 10, &len);
			else
				put_digit(va_arg(args, long long int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(args), len);
}

int main(void)
{
	ft_printf("Hello%s", " There\n");
	return 0;
}
