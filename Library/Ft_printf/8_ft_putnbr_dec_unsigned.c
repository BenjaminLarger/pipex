/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_ft_putnbr_dec_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:27:50 by blarger           #+#    #+#             */
/*   Updated: 2024/01/12 19:02:17 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n == 2147483647)
		return (10);
	else if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	temp;
	int		len;

	len = ft_len_int_unsigned(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		temp = n + '0';
		write(1, &temp, 1);
	}
	return (len);
}

int	ft_putnbr_dec_unsigned(double n)
{
	int				integer_part;
	float			decimal_part;
	int				round_decimal;
	int				len;
	unsigned int	unsigned_num;

	if (n < 0)
	{
		unsigned_num = n;
		return (ft_putnbr_unsigned(unsigned_num));
	}
	if (n == 2147483648.000000)
		return (ft_putstr_fd("2147483647", 1));
	len = ft_len_int((int)n);
	integer_part = (int long long)n;
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

/* int main()
{
	float num = 0.34;
	ft_putnbr_dec_unsigned(num);
} */