#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int a = 5;
	int b = 7;
	printf("Original\n A: %d B:%d\n\n", a, b);
	ft_swap(&a, &b);
	printf("Modified\n A: %d, B: %d\n\n", a, b);
}
