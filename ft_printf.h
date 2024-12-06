#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// Prototypes des fonctions
int     ft_printf(const char *format, ...);
int     ft_putchar(char c);
int     ft_putstr(char *s);
int     ft_putnbr(int n);
int     ft_putnbr_unsigned(unsigned int n);
int     ft_putnbr_base(unsigned long nbr, char *base);
int     ft_strlen(const char *str);

#endif
