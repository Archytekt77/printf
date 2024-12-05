#include <stdio.h>

void	print_pointer(void *ptr)
{
	printf("Adresse mémoire : 0x%lx\n", (unsigned long)ptr);
}

int	main(void)
{
	int x = 42;
	print_pointer(&x);
	return (0);
}