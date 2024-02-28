/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_putnbr_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:44:09 by blarger           #+#    #+#             */
/*   Updated: 2024/01/12 19:01:55 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_dec(double n)
{
	int		integer_part;
	float	decimal_part;
	int		round_decimal;
	int		len;

	len = ft_len_int((int)n);
	if (n == 2147483647)
		return (ft_putstr_fd("2147483647", 1), 10);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = n * -1;
	}
	integer_part = (long long int)n;
	ft_putnbr(integer_part);
	decimal_part = n - integer_part;
	round_decimal = (int)(decimal_part * 10 + 0.5);
	if (round_decimal > 0)
	{
		len++;
		ft_putchar('.');
		ft_putnbr(round_decimal);
	}
	return (len);
}

/*  int	main()
{
//	char *string = "ahhahah";
	ft_printf("%d\n",-167499210);
	printf("%d",-167499210);
} */