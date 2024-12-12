/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:13:06 by lmaria            #+#    #+#             */
/*   Updated: 2024/12/12 16:50:49 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

void	test_ft_printf(const char *format, ...)
{
	int	nb;
	int	nb2;

	va_list args1, args2;
	va_start(args1, format);
	va_copy(args2, args1);
	printf("Expected display: ");
	nb = printf(format, args1);
	printf("\n");
	printf("Actual display: ");
	fflush(stdout);
	nb2 = ft_printf(format, args2);
	printf("\n");
	printf("Expected return = %d\n", nb);
	printf("Actual return = %d\n", nb2);
	va_end(args1);
	va_end(args2);
	if (nb == nb2)
		printf("Test Passed ✅\n");
	else
		printf("Test Failed ❌\n");
}

int	main(void)
{
	int	x;

	printf("=== Testing ft_printf ===\n\n");
	printf("Test %%c (Charactere)\n");
	test_ft_printf("%c", 'A');
	printf("\n");
	printf("Test %%s (String)\n");
	test_ft_printf("%s", "Hello, World!");
	test_ft_printf("%s", "");
	printf("\n");
	printf("Test %%p (Pointer)\n");
	x = 42;
	test_ft_printf("%p", &x);
	test_ft_printf("%p", NULL);
	printf("\n");
	// // Test %d et %i : Entiers signés
	// printf("Test %%d et %%i (Entiers signés)\n");
	// test_ft_printf("Decimal: %d", 42);
	// test_ft_printf("Negative: %d", -42);
	// test_ft_printf("Integer: %i", 1234);
	// printf("\n");
	// // Test %u : Entiers non signés
	// printf("Test %%u (Entiers non signés)\n");
	// test_ft_printf("Unsigned: %u", 42);
	// test_ft_printf("Max Unsigned: %u", 4294967295U);
	// printf("\n");
	// // Test %x et %X : Hexadécimal
	// printf("Test %%x et %%X (Hexadécimal)\n");
	// test_ft_printf("Hex lowercase: %x", 255);
	// test_ft_printf("Hex uppercase: %X", 255);
	// printf("\n");
	// // Test %% : Signe pourcentage
	// printf("Test %%%% (Pourcentage)\n");
	// test_ft_printf("Percent: %%");
	// printf("\n");
	printf("=== Tests Completed ===\n");
	return (0);
}
