/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:56:28 by lmaria            #+#    #+#             */
/*   Updated: 2024/12/09 16:38:00 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				count += ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*format == 'x')
				count += ft_putnbr_base(va_arg(args, unsigned int),
						"0123456789abcdef");
			else if (*format == 'X')
				count += ft_putnbr_base(va_arg(args, unsigned int),
						"0123456789ABCDEF");
			else if (*format == 'p')
			{
				count += ft_putstr("0x");
				count += ft_putnbr_base(va_arg(args, unsigned long),
						"0123456789abcdef");
			}
			else if (*format == '%')
				count += ft_putchar('%');
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
