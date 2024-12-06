#include "ft_printf.h"
#include <stdio.h>

int main() {
    ft_printf("Caractère : %c\n", 'A');
    ft_printf("Chaîne : %s\n", "Hello, world!");
    ft_printf("Entier : %d\n", 42);
    ft_printf("Hexadécimal : %x\n", 255);
    ft_printf("Pointeur : %p\n", (void *)&main);
    ft_printf("Pourcentage : %%\n");
    return 0;
}
