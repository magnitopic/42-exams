void ft_swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int a = 15;
	int b = 42;
	ft_swap(&a, &b);
	return 0;
}
