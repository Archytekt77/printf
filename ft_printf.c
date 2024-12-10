/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:56:28 by lmaria            #+#    #+#             */
/*   Updated: 2024/12/10 19:42:35 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_conversion(const char *format, va_list args, int count,
		unsigned long ptr)
{
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*format == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			return (count += ft_putstr("(nil)"));
		count += ft_putstr("0x");
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	}
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

static int	process_format_string(const char *format, va_list args, int count)
{
	unsigned long	ptr;

	ptr = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = process_conversion(format, args, count, ptr);
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = process_format_string(format, args, count);
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int	nb;
	int	nb2;

	nb = ft_printf("abcde % \n");
	nb2 = printf("abcde % \n");
	printf("%d\n", nb);
	printf("%d\n", nb2);
	return (0);
}
