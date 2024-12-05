#include <stdio.h>

void	print_base_recursive(unsigned int num, int base, char *digits)
{
	if (num >= base)
		print_base_recursive(num / base, base, digits);
	putchar(digits[num % base]);
}

int	main(void)
{
	unsigned int number = 255;
	printf("Hexadecimal : ");
	print_base_recursive(number, 16, "0123456789abcdef");
	printf("\n");
	return (0);
}