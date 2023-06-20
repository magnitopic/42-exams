#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int a = 5;
	int b = 7;
	ft_swap(&a, &b);
	printf("a: %d b:%d", a, b);
}
