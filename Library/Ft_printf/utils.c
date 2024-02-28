/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:18:47 by blarger           #+#    #+#             */
/*   Updated: 2023/12/14 11:50:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
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

int	get_hex_len(unsigned long str)
{
	int	count;

	if (str == 0)
		return (1);
	count = 0;
	if (!str)
		return (0);
	while (str)
	{
		count++;
		str >>= 4;
	}
	return (count);
}

char	*conv_hex_low(int hex_len, unsigned long ptr_val, char *hex_str)
{
	int	i;
	int	res;

	res = 0;
	i = hex_len - 1;
	while (i >= 0)
	{
		res = ptr_val % 16;
		if (res < 10)
			hex_str[i] = '0' + res;
		else
			hex_str[i] = 'a' + (res - 10);
		ptr_val = ptr_val / 16;
		i--;
	}
	hex_str[hex_len] = '\0';
	return (hex_str);
}
