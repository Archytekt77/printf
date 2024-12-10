/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:56:28 by lmaria            #+#    #+#             */
/*   Updated: 2024/12/10 15:33:04 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format2(const char *format, va_list args, int count,
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

static int	process_format(const char *format, va_list args)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	ptr = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = process_format2(format, args, count, ptr);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = process_format(format, args);
	va_end(args);
	return (count);
}
