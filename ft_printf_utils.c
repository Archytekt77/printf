#include "ft_printf.h"

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *s) {
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
        count += ft_putchar(*s++);
    return count;
}

int ft_putnbr(int n) {
    int count = 0;
    if (n == -2147483648)
        return ft_putstr("-2147483648");
    if (n < 0) {
        count += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        count += ft_putnbr(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_putnbr_unsigned(unsigned int n) {
    int count = 0;
    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_putnbr_base(unsigned long nbr, char *base) {
    int count = 0;
    int base_len = ft_strlen(base);

    if (nbr >= (unsigned long)base_len)
        count += ft_putnbr_base(nbr / base_len, base);
    count += ft_putchar(base[nbr % base_len]);
    return count;
}

int ft_strlen(const char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}
