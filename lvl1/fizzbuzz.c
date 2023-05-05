#include <unistd.h>

static void write_char(int num)
{
	char values[10] = "0123456789";
	if (num > 9)
		write_char(num / 10);
	write(1, &values[num % 10], 1);
}

int main(void)
{
	int i = 0;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (i % 5 != 0 && i % 3 != 0)
			write_char(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
