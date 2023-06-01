#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char *str;
	int len = 0;
	int aux;

	aux = nbr;
	if (nbr <= 0)
		len++;
	while (aux)
	{
		aux /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

int	main(void)
{
	printf("%s", ft_itoa(55));
	return (0);
}