#include <unistd.h>

int	ft_strlen(char *str)
{
	int count = 0;

	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	int		i;
	int		s1_len;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		s1_len = ft_strlen(s1);
		while (*s2)
		{
			i = 0;
			while (s1[i] == *s2)
			{
				if (i + 1 == s1_len)
				{
					write(1, "1\n", 2);
					return (0);
				}
				i++;
				s2++;
			}
			s2++;
		}
		write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
