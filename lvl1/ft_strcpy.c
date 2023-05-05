#include <unistd.h>

char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return s1;
}

/* int main(void)
{
	char *s2= "hi";
	char s1[3];
	write(1, ft_strcpy(s1, s2), 2);
	return 0;
} */
